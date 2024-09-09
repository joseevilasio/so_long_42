/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:51:59 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/09 21:14:12 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_create_matrix(char *pathname, t_data *data)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	data->map = (char **) malloc((data->height + 1) * sizeof(char *));
	if (!data->map)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
	fd = ft_open(pathname, data);
	line = ft_strremove(get_next_line(fd), data);
	while (line && y < data->height)
	{
		data->map[y] = ft_strdup(line);
		if (!data->map[y])
			ft_error_handler("Error\n", ERROR_MALLOC, line, data);
		free(line);
		line = ft_strremove(get_next_line(fd), data);
		y++;
	}
	data->map[y] = NULL;
	close(fd);
}

static int	ft_checkwall(char *line, t_data *data)
{
	int	i;

	i = 0;
	if ((int) ft_strlen(line) != data->width)
		return (-1);
	if (data->height == 1 || i == data->height - 1)
	{
		while (line[i])
		{
			if (line[i] == '1')
				i++;
			else
				return (-1);
		}
	}
	else
	{
		if (line[0] != '1' || line[data->width - 1] != '1')
			return (-1);
	}
	return (0);
}

static int	ft_checkitems(char *line, t_data *data)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'P')
		{
			data->plr->pos_h = data->height - 1;
			data->plr->pos_w = x;
			data->p++;
		}
		if (line[x] == 'C')
			data->c++;
		if (line[x] == 'E')
			data->e++;
		if (line[x] == 'A')
		{
			data->enm->pos_h = data->height - 1;
			data->enm->pos_w = x;
			data->enemy_++;
		}
		x++;
	}
	return (checkchar(line));
}

static void	ft_ensure(char *pathname, t_data *data)
{
	char	*line;
	int		fd;
	int		error;

	error = 0;
	fd = ft_open(pathname, data);
	line = ft_strremove(get_next_line(fd), data);
	data->width = (int) ft_strlen(line);
	while (line)
	{
		if (ft_checkwall(line, data) == -1 || ft_checkitems(line, data) == -1)
			error = -1;
		free(line);
		line = ft_strremove(get_next_line(fd), data);
		if (!line)
			break ;
		data->height++;
	}
	close(fd);
	if (data->p != 1 || data->e != 1 || data->c < 1 /* || data->enemy_ < 1 */)
		ft_error_handler("Invalid map: items", ERROR_MAP, NULL, data);
	if (data->height <= 1 || data->width <= 1 || error == -1)
		ft_error_handler("Invalid map: format", ERROR_MAP, NULL, data);
}

void	ft_loadmap(char *pathname, t_data *data)
{
	char	**copy_map;

	copy_map = NULL;
	ft_ensure(pathname, data);
	ft_create_matrix(pathname, data);
	copy_map = ft_copymap(data->map, data);
	ft_floodfill(copy_map, data, data->plr->pos_w, data->plr->pos_h);
	if (data->ff_c != data->c || data->ff_e != 1)
	{
		ft_free_map(copy_map);
		ft_error_handler("Invalid map: without exit", ERROR_MAP, NULL, data);
	}
	ft_free_map(copy_map);
	data->new_map = ft_copymap(data->map, data);
}
