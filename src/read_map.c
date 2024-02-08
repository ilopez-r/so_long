/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:44:30 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/01/24 17:15:16 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_columns(char *line, t_game *game, int fd, char *map_name)
{
	int	i;

	i = -1;
	fd = open(map_name, 0);
	line = get_next_line (fd);
	while (++i < game->lines)
	{
		game->columns = ft_strlen (line);
		if (line[game->columns - 1] != '\n')
			game->columns++;
		game->map[i] = ft_calloc (game->columns, sizeof (char *));
		game->map_way[i] = ft_calloc (game->columns, sizeof (char *));
		ft_strlcpy (game->map[i], line, game->columns);
		ft_strlcpy (game->map_way[i], line, game->columns);
		free (line);
		line = get_next_line (fd);
	}
	game->columns--;
	game->map[i] = NULL;
	game->map_way[i] = NULL;
	close (fd);
	free (line);
	return (EXIT_SUCCESS);
}

static int	read_lines(char *line, t_game *game, int fd, char *map_name)
{
	fd = open(map_name, 0);
	line = get_next_line (fd);
	if (line == NULL)
		return (ft_printf("Mapa vacío\n"), EXIT_FAILURE);
	free (line);
	while (line != NULL)
	{
		game->lines++;
		line = get_next_line (fd);
		free (line);
	}
	game->map = ft_calloc (game->lines + 1, sizeof (char *));
	game->map_way = ft_calloc (game->lines + 1, sizeof (char *));
	if (game->map == NULL || game->map_way == NULL)
	{
		free (line);
		return (EXIT_FAILURE);
	}
	close (fd);
	if (read_columns(line, game, fd, map_name) == 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	read_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

	line = 0;
	fd = open (map_name, 0);
	if (fd < 0)
		return (ft_printf("No se puede abrir el mapa\n"), EXIT_FAILURE);
	if (read_lines(line, game, fd, map_name) == 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
