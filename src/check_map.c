/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:17:33 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/01/24 15:49:59 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_game *game)
{
	int	line;
	int	i;

	i = 0;
	line = game->lines - 1;
	while (i < game->columns)
	{
		if (game->map[line][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	while (--line != 0)
	{
		if (game->map[line][0] != '1'
			|| game->map[line][i - 1] != '1')
			return (EXIT_FAILURE);
	}
	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_objects(t_game *game, int line, int i)
{
	line = game->lines - 1;
	while (--line != 0)
	{
		i = -1;
		while (++i <= game->columns - 1)
		{
			if (game->map[line][i] != '0' && game->map[line][i] != '1'
				&& game->map[line][i] != 'C' && game->map[line][i] != 'P'
				&& game->map[line][i] != 'E')
				return (ft_printf ("Carácter erróneo\n"), EXIT_FAILURE);
			if (game->map[line][i] == 'C')
				game->c++;
			if (game->map[line][i] == 'P')
			{
				game->p++;
				game->p_position.x = i;
				game->p_position.y = line;
			}
			if (game->map[line][i] == 'E')
				game->e++;
		}
	}
	if (game->p != 1 || game->e != 1 || game->c == 0)
		return (ft_printf ("Error de objetos\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_way(t_game *game, t_point current)
{
	if (current.x >= game->columns || current.y >= game->lines || current.x < 0
		|| current.y < 0 || game->map_way[current.y][current.x] == '1'
		|| game->map_way[current.y][current.x] == '*')
		return ;
	if (game->map_way[current.y][current.x] == 'C')
		game->c_copy++;
	if (game->map_way[current.y][current.x] == 'E')
	{
		game->e_copy++;
		game->local_exit.y = current.y;
		game->local_exit.x = current.x;
	}
	game->map_way[current.y][current.x] = '*';
	check_way(game, (t_point){current.x - 1, current.y});
	check_way(game, (t_point){current.x + 1, current.y});
	check_way(game, (t_point){current.x, current.y - 1});
	check_way(game, (t_point){current.x, current.y + 1});
}

int	check_map(t_game *game)
{
	int	i;
	int	line;

	i = ft_strlen(game->map[0]);
	line = game->lines;
	while (--line >= 0)
	{
		if ((size_t)i != ft_strlen(game->map[line]))
			return (ft_printf("Mapa no rectangular\n"), EXIT_FAILURE);
	}
	if (check_wall(game) == 1)
		return (ft_printf ("Muros pochos\n"), EXIT_FAILURE);
	if (check_objects(game, 0, 0) == 1)
		return (EXIT_FAILURE);
	check_way(game, game->p_position);
	if (game->c != game->c_copy || game->e != game->e_copy)
		return (ft_printf("Tabaco o exit no accesible\n"), EXIT_FAILURE);
	game->c = 0;
	return (EXIT_SUCCESS);
}
