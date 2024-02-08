/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:17:32 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/01/26 13:49:13 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	images(t_game *g, int x, int y, void *img)
{
	if (g->map[g->p_position.y][g->p_position.x] == 'E')
		mlx_image_to_window(g->mlx, g->i_sc, g->p_position.x * 48,
			g->p_position.y * 48);
	if (g->map[g->p_position.y][g->p_position.x] != 'E'
		&& g->map[g->p_position.y][g->p_position.x] != '1')
		mlx_image_to_window(g->mlx, g->i_floor, g->p_position.x * 48,
			g->p_position.y * 48);
	g->p_position.x = x;
	g->p_position.y = y;
	if (g->map[g->p_position.y][g->p_position.x] == 'C')
	{
		mlx_image_to_window(g->mlx, g->i_floor, g->p_position.x * 48,
			g->p_position.y * 48);
		g->map[g->p_position.y][g->p_position.x] = '0';
		g->c++;
		if (g->c == g->c_copy)
			mlx_image_to_window(g->mlx, g->i_sa, g->local_exit.x * 48,
				g->local_exit.y * 48);
	}
	mlx_image_to_window(g->mlx, img, g->p_position.x * 48,
		g->p_position.y * 48);
}

static void	keypress(t_game *g, int x, int y, void *img)
{
	g->moves++;
	ft_printf("Número de movimientos: %d\n", g->moves);
	if (g->map[y][x] == 'E' && g->c == g->c_copy)
	{
		mlx_close_window(g->mlx);
		ft_printf("\n");
		ft_printf("GANASTE :)\n");
		ft_printf("\n");
	}
	else if (g->map[y][x] == 'E' || g->map[y][x] == 'C' || g->map[y][x] != '1')
		images (g, x, y, img);
}

void	player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y - 1, game->i_pd);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x - 1, game->p_position.y, game->i_pi);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y + 1, game->i_pd);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x + 1, game->p_position.y, game->i_pd);
}
