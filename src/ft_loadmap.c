/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:51:59 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/15 21:45:29 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_create_matrix(char *pathname, int height, int **map)
{
	int		y;
	int		x;
	int		fd;
	char	*line;

	y = 0;
	fd = ft_open(pathname);
	line = ft_strremove(get_next_line(fd), "\n");
	while (line && y < height)
	{
		x = 0;
		while (line[x])
		{
			map[y][x] = line[x];
			x++;
		}
		y++;
		free(line);
		line = ft_strremove(get_next_line(fd), "\n");
	}
	close(fd);
}

static void	ft_checkwall(char *line, int x, int y)
{
	int	i;

	i = 0;
	if ((int) ft_strlen(line) != x)
		ft_error_handler("Invalid map, rectangle fail", ERROR_MAP, 1, line);
	if (y == 1 || i == y - 1)
	{
		while (line[i])
		{
			if (line[i] == '1')
				i++;
			else
				ft_error_handler("Invalid map, wall fail", ERROR_MAP, 1, line);
		}
	}
	else
	{
		if (line[0] != '1' || line[x - 1] != '1')
			ft_error_handler("Invalid map, wall fail", ERROR_MAP, 1, line);
	}
}

static void	ft_checkitems(char *line, t_init *map_init, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'P')
		{
			map_init->pos_p[0] = y;
			map_init->pos_p[1] = x;
			map_init->p++;
		}
		if (line[x] == 'C')
			map_init->c++;
		if (line[x] == 'E')
			map_init->e++;
		x++;
	}
}

static void	ft_mapsize(char *pathname, t_init *map_init)
{
	char	*line;
	int		fd;

	fd = ft_open(pathname);
	line = ft_strremove(get_next_line(fd), "\n");
	map_init->size[1] = (int) ft_strlen(line); //width
	while (line)
	{
		ft_checkwall(line, map_init->size[1], map_init->size[0]);
		ft_checkitems(line, map_init, map_init->size[0]);
		free(line);
		line = ft_strremove(get_next_line(fd), "\n");
		if (!line)
			break ;
		map_init->size[0]++;
	}
	close(fd);
	if (map_init->p != 1 || map_init->e != 1 || map_init->c < 1)
		ft_error_handler("Invalid items", ERROR_MAP, 1, NULL);
	if (map_init->size[0] <= 1 || map_init->size[1] <= 1)
		ft_error_handler("Invalid map, empty map", ERROR_MAP, 1, NULL);
}

int	**ft_loadmap(char *pathname)
{
	t_init	map_init;
	int		**map;
	int		i;

	i = 0;
	ft_init(&map_init);
	ft_mapsize(pathname, &map_init);
	map = (int **) malloc(map_init.size[0] * sizeof(int *));
	while (i < map_init.size[0])
	{
		map[i] = (int *) malloc(map_init.size[1] * sizeof(int));
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			ft_error_handler("Error", ERROR_MALLOC, 0, NULL);
		}
		i++;
	}
	ft_create_matrix(pathname, map_init.size[0], map);
	ft_printf("-h-%d -w-%d\n", map_init.size[0], map_init.size[1]);
	ft_printmap(map, map_init);
	ft_floodfill(map, &map_init, map_init.pos_p[0], map_init.pos_p[1]);
	ft_printf("Coletaveis: %d Exit: %d\n", map_init.ff_c, map_init.ff_e);
	if (map_init.ff_c != map_init.c || map_init.ff_e != 1)
		ft_error_handler("Invalid map, without exit", ERROR_MAP, 1, NULL);
	ft_printf("\n\n");
	ft_printmap(map, map_init);
	while (i--)
		free(map[i]);
	// free(map);
	free(map_init.size);
	free(map_init.pos_p);
	return (map);
}
