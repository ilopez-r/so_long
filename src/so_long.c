/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:02:50 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/02/08 12:13:55 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	ft_leaks(void)
{
	system("leaks -q so_long");

	copiar esta: atexit(ft_leaks);
}*/

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->map == NULL && game->map_way == NULL)
		return (free(game));
	while (game->map[i] != NULL && game->map_way[i] != NULL)
	{
		free(game->map[i]);
		free(game->map_way[i]);
		i++;
	}
	free(game->map);
	free(game->map_way);
	free(game);
}

static void	initialize(t_game *game)
{
	game->map = NULL;
	game->map_way = NULL;
	game->lines = 0;
	game->columns = 0;
	game->c = 0;
	game->c_copy = 0;
	game->e = 0;
	game->e_copy = 0;
	game->p = 0;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	*g;
	int		i;

	i = 0;
	if (argc != 2)
		return (ft_printf ("No hay mapa\n"), EXIT_FAILURE);
	g = ft_calloc(1, sizeof(t_game));
	initialize(g);
	if (check_format(argv[1]) == 1)
		return (free_all(g), ft_printf ("Formato mapa incorrecto\n"), 1);
	if (read_map(g, argv[1]) == 1)
		return (free_all(g), EXIT_FAILURE);
	if (check_map(g) == 1)
		return (free_all(g), EXIT_FAILURE);
	g->mlx = mlx_init(48 * g->columns, 48 * g->lines, "SO_LONG", false);
	if (!g->mlx)
		return (free_all(g), EXIT_FAILURE);
	if (texture_to_image(g) == 1 || image_to_window(g) == 1)
		return (free_all(g), ft_printf ("Error imágenes\n"), EXIT_FAILURE);
	mlx_key_hook (g->mlx, &player_move, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (free_all(g), EXIT_SUCCESS);
}
