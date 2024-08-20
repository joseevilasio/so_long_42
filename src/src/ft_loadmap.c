/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:51:59 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/20 19:11:15 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_create_matrix(char *pathname, t_data *data)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	data->map = (char **) malloc((data->height + 1) * sizeof(char *));
	if (!data->map)
		ft_error_handler("Error", ERROR_MALLOC, NULL, data);
	fd = ft_open(pathname, data);
	line = ft_strremove(get_next_line(fd), "\n");
	while (line && y < data->height)
	{
		data->map[y] = ft_strdup(line);
		if (!data->map[y])
			ft_error_handler("Error", ERROR_MALLOC, line, data);
		free(line);
		line = ft_strremove(get_next_line(fd), "\n");
		y++;
	}
	data->map[y] = NULL;
	close(fd);
}

static void	ft_checkwall(char *line, t_data *data)
{
	int	i;

	i = 0;
	if ((int) ft_strlen(line) != data->width)
		ft_error_handler("Map: rectangle fail", ERROR_MAP, line, data);
	if (data->height == 1 || i == data->height - 1)
	{
		while (line[i])
		{
			if (line[i] == '1')
				i++;
			else
				ft_error_handler("Map: wall fail", ERROR_MAP, line, data);
		}
	}
	else
	{
		if (line[0] != '1' || line[data->width - 1] != '1')
			ft_error_handler("Map: wall fail", ERROR_MAP, line, data);
	}
}

static void	ft_checkitems(char *line, t_data *data)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'P')
		{
			data->pplayer_h = data->height - 1;
			data->pplayer_w = x;
			data->p++;
		}
		if (line[x] == 'C')
			data->c++;
		if (line[x] == 'E')
			data->e++;
		x++;
	}
}

static void	ft_ensure(char *pathname, t_data *data)
{
	char	*line;
	int		fd;

	fd = ft_open(pathname, data);
	line = ft_strremove(get_next_line(fd), "\n");
	data->width = (int) ft_strlen(line);
	while (line)
	{
		ft_checkwall(line, data);
		ft_checkitems(line, data);
		free(line);
		line = ft_strremove(get_next_line(fd), "\n");
		if (!line)
			break ;
		data->height++;
	}
	close(fd);
	if (data->p != 1 || data->e != 1 || data->c < 1)
		ft_error_handler("Map: Invalid items", ERROR_MAP, NULL, data);
	if (data->height <= 1 || data->width <= 1)
		ft_error_handler("Map: empty map", ERROR_MAP, NULL, data);
}

void	ft_loadmap(char *pathname, t_data *data)
{
	char	**copy_map;

	copy_map = NULL;
	ft_data_init(data);
	ft_ensure(pathname, data);
	ft_create_matrix(pathname, data);
	copy_map = ft_copymap(data->map, data);
	ft_floodfill(copy_map, data, data->pplayer_h, data->pplayer_w);
	if (data->ff_c != data->c || data->ff_e != 1)
	{
		ft_free_map(copy_map);
		ft_error_handler("Map: without exit", ERROR_MAP, NULL, data);
	}
	ft_free_map(copy_map);
	data->new_map = ft_copymap(data->map, data);
}
