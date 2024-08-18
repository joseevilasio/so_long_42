/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:36:31 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/18 22:30:41 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *pathname, t_data *data)
{
	int		fd;
	char	*filename;

	filename = ft_strnstr(pathname, ".ber", ft_strlen(pathname));
	if (filename == NULL || ft_strlen(filename) != 4)
		ft_error_handler("Invalid file type.", ERROR_TYPE, NULL, data);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		ft_error_handler("Error", ERROR_OPEN, NULL, data);
	return (fd);
}

char	*ft_strremove(char *str, char *target)
{
	char	*new_str;

	new_str = ft_strtrim(str, target);
	if (!new_str)
	{
		free(new_str);
		return (str);
	}
	free(str);
	return (new_str);
}

void	ft_data_init(t_data *data)
{
	data->width = 0;
	data->height = 1;
	data->pplayer_h = 0;
	data->pplayer_w = 0;
	data->p = 0;
	data->e = 0;
	data->c = 0;
	data->ff_e = 0;
	data->ff_c = 0;
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->img_size = 0;
	data->img_wall = NULL;
	data->img_coll = NULL;
	data->img_player = NULL;
	data->img_exit = NULL;
	data->img_empty = NULL;
}

void	ft_printmap(char **source, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	ft_printf("\n PRINT MAP \n");
	while (y < height)
	{
		x = 0;
		while (x < width)
			ft_printf("%c", source[y][x++]);
		ft_printf("\n");
		y++;
	}
}

void	ft_floodfill(char **map, t_data *data, int x, int y)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		data->ff_e++;
	if (map[y][x] == 'C')
		data->ff_c++;
	map[y][x] = '1';
	ft_floodfill(map, data, x + 1, y);
	ft_floodfill(map, data, x - 1, y);
	ft_floodfill(map, data, x, y + 1);
	ft_floodfill(map, data, x, y - 1);
}
