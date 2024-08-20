/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:36:31 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/20 22:36:56 by joneves-         ###   ########.fr       */
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
