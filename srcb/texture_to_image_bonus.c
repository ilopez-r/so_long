/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:51:09 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/01/25 12:52:13 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->t_coin);
	mlx_delete_texture(game->t_floor);
	mlx_delete_texture(game->t_enemy);
	mlx_delete_texture(game->t_pd);
	mlx_delete_texture(game->t_pi);
	mlx_delete_texture(game->t_sa);
	mlx_delete_texture(game->t_sc);
	mlx_delete_texture(game->t_wall);
}

int	image_error(t_game *g)
{
	if (!g->t_coin || !g->t_enemy || !g->t_floor || !g->t_pd || !g->t_pi
		|| !g->t_sa || !g->t_sc || !g->t_wall || !g->i_coin || !g->i_enemy
		|| !g->i_floor || !g->i_pd || !g->i_pi || !g->i_sa || !g->i_sc
		|| !g->i_wall)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	texture_to_image(t_game *game)
{
	game->t_coin = mlx_load_png("./images/coin.png");
	game->t_enemy = mlx_load_png("./images/enemy.png");
	game->t_floor = mlx_load_png("./images/floor.png");
	game->t_pd = mlx_load_png("./images/pd.png");
	game->t_pi = mlx_load_png("./images/pi.png");
	game->t_sa = mlx_load_png("./images/sa.png");
	game->t_sc = mlx_load_png("./images/sc.png");
	game->t_wall = mlx_load_png("./images/wall.png");
	game->i_coin = mlx_texture_to_image(game->mlx, game->t_coin);
	game->i_enemy = mlx_texture_to_image(game->mlx, game->t_enemy);
	game->i_floor = mlx_texture_to_image(game->mlx, game->t_floor);
	game->i_pd = mlx_texture_to_image(game->mlx, game->t_pd);
	game->i_pi = mlx_texture_to_image(game->mlx, game->t_pi);
	game->i_sa = mlx_texture_to_image(game->mlx, game->t_sa);
	game->i_sc = mlx_texture_to_image(game->mlx, game->t_sc);
	game->i_wall = mlx_texture_to_image(game->mlx, game->t_wall);
	clean_textures(game);
	if (image_error(game) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
