/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:03:58 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/01/25 12:49:32 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libftc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	int				lines;
	int				columns;
	char			**map;
	char			**map_way;
	int				c;
	int				c_copy;
	int				e;
	int				e_copy;
	int				p;
	int				moves;
	t_point			local_exit;
	t_point			p_position;
	mlx_t			*mlx;
	mlx_texture_t	*t_coin;
	mlx_image_t		*i_coin;
	mlx_texture_t	*t_floor;
	mlx_image_t		*i_floor;
	mlx_texture_t	*t_pd;
	mlx_image_t		*i_pd;
	mlx_texture_t	*t_pi;
	mlx_image_t		*i_pi;
	mlx_texture_t	*t_sa;
	mlx_image_t		*i_sa;
	mlx_texture_t	*t_sc;
	mlx_image_t		*i_sc;
	mlx_texture_t	*t_wall;
	mlx_image_t		*i_wall;
}	t_game;

int		check_format(char *map_name);
int		read_map(t_game *game, char *map_name);
int		check_map(t_game *game);
int		texture_to_image(t_game *game);
int		image_to_window(t_game *game);
void	player_move(mlx_key_data_t keydata, void *param);

#endif
