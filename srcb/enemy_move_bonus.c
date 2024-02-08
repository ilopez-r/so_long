/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:38:11 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/01/26 13:09:37 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_previous_images(t_game *g)
{
	if (g->map[g->e_position.y][g->e_position.x] == 'E')
	{
		mlx_image_to_window(g->mlx, g->i_sc, g->e_position.x * 48,
			g->e_position.y * 48);
		if (g->c == g->c_copy)
			mlx_image_to_window(g->mlx, g->i_sa, g->e_position.x * 48,
				g->e_position.y * 48);
	}
	if (g->map[g->e_position.y][g->e_position.x] != 'E')
	{
		mlx_image_to_window(g->mlx, g->i_floor, g->e_position.x * 48,
			g->e_position.y * 48);
		if (g->map[g->e_position.y][g->e_position.x] == 'C'
			&& g->c != g->c_copy)
			mlx_image_to_window(g->mlx, g->i_coin, g->e_position.x * 48,
				g->e_position.y * 48);
	}
}

static void	move_images(t_game *g, int x, int y, void *img)
{
	if (g->map[y][x] != '1')
	{
		move_previous_images(g);
		g->e_position.x = x;
		g->e_position.y = y;
		if (g->map[g->e_position.y][g->e_position.x] == 'E')
		{
			mlx_image_to_window(g->mlx, g->i_sc, g->e_position.x * 48,
				g->e_position.y * 48);
			if (g->c == g->c_copy)
				mlx_image_to_window(g->mlx, g->i_sa, g->e_position.x * 48,
					g->e_position.y * 48);
		}
		if (g->map[g->e_position.y][g->e_position.x] != 'E')
		{
			mlx_image_to_window(g->mlx, g->i_floor, g->e_position.x * 48,
				g->e_position.y * 48);
			if (g->map[g->e_position.y][g->e_position.x] == 'C'
				&& g->c != g->c_copy)
				mlx_image_to_window(g->mlx, g->i_coin, g->e_position.x * 48,
					g->e_position.y * 48);
		}
		mlx_image_to_window(g->mlx, img, g->e_position.x * 48,
			g->e_position.y * 48);
	}
}

void	calculate_direction(t_game *game, int *dx, int *dy)
{
	*dx = (game->p_position.x) - (game->e_position.x);
	*dy = (game->p_position.y) - (game->e_position.y);
}

void	direction_enemy(t_game *g, int dx, int dy)
{
	if (dx > 0)
		move_images(g, g->e_position.x + 1, g->e_position.y, g->i_enemy);
	if (dx < 0)
		move_images(g, g->e_position.x - 1, g->e_position.y, g->i_enemy);
	if (dy > 0)
		move_images(g, g->e_position.x, g->e_position.y + 1, g->i_enemy);
	if (dy < 0)
		move_images(g, g->e_position.x, g->e_position.y - 1, g->i_enemy);
}

void	enemy_move(t_game *game)
{
	int	dx;
	int	dy;

	calculate_direction(game, &dx, &dy);
	game->enemy_move_timer += game->mlx->delta_time;
	if (game->enemy_move_timer >= 0.4)
	{
		direction_enemy(game, dx, dy);
		game->enemy_move_timer = 0;
	}
	if (game->e_position.x == game->p_position.x
		&& game->e_position.y == game->p_position.y)
	{
		ft_printf("\n");
		ft_printf("MORISTE :(\n");
		ft_printf("\n");
		mlx_close_window(game->mlx);
	}
}
