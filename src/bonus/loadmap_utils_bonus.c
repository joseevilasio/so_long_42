/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:36:31 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/09 21:23:03 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

char	*ft_strremove(char *str, t_data *data)
{
	char	*new_str;

	new_str = NULL;
	if (str)
	{
		if (!ft_strchr(str, '\n'))
			return (str);
		new_str = ft_strtrim(str, "\n");
		if (!new_str)
			ft_error_handler("Error\n", ERROR_MALLOC, str, data);
		free(str);
		return (new_str);
	}
	return (NULL);
}

void	ft_floodfill(char **map, t_data *data, int x, int y)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
		data->ff_e++;
	if (map[y][x] == 'C')
		data->ff_c++;
	map[y][x] = 'V';
	ft_floodfill(map, data, x + 1, y);
	ft_floodfill(map, data, x - 1, y);
	ft_floodfill(map, data, x, y + 1);
	ft_floodfill(map, data, x, y - 1);
}

char	**ft_copymap(char **source, t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	map = NULL;
	map = (char **) malloc((data->height + 1) * sizeof(char *));
	if (!map)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
	while (source[i])
	{
		map[i] = ft_strdup(source[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	checkchar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'C' && s[i] != 'P'
			&& s[i] != 'E' && s[i] != 'A')
			return (-1);
		i++;
	}
	return (0);
}

/* void	ft_printmap(char **source)
{
	int	i;

	i = 0;
	ft_printf("\n PRINT MAP \n");
	while (source[i])
	{
		ft_printf("%s\n", source[i]);
		i++;
	}
} */
