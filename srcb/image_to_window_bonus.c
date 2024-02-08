/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:29:04 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/01/25 14:18:44 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	image_to_window(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (g->map[j] != NULL)
	{
		i = 0;
		while (g->map[j][i] != '\n' && g->map[j][i] != '\0')
		{
			mlx_image_to_window (g->mlx, g->i_floor, i * 48, j * 48);
			if (g->map[j][i] == '1')
				mlx_image_to_window (g->mlx, g->i_wall, i * 48, j * 48);
			if (g->map[j][i] == 'C')
				mlx_image_to_window (g->mlx, g->i_coin, i * 48, j * 48);
			if (g->map[j][i] == 'P')
				mlx_image_to_window (g->mlx, g->i_pd, i * 48, j * 48);
			if (g->map[j][i] == 'E')
				mlx_image_to_window (g->mlx, g->i_sc, i * 48, j * 48);
			if (g->map[j][i] == 'M')
				mlx_image_to_window (g->mlx, g->i_enemy, i * 48, j * 48);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
