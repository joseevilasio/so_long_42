/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:47:14 by joneves-          #+#    #+#             */
/*   Updated: 2024/07/28 23:12:47 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall(char *wall, int lines, int i)
{
	int	z;

	z = 0;
	if (i == 0 || i == lines)
	{
		while (wall[z])
		{
			if (wall[z] == '1' || wall[z] == '\n')
				z++;
			else
			{
				free(wall);
				ft_error_handler("Invalid map, wall fail.", ERROR_INVALID_TYPE, 1);
			}
		}
	}
	else
	{
		if (wall[0] != '1' || wall[ft_strlen(wall) - 2] != '1')
		{
			free(wall);
			ft_error_handler("Invalid map, wall fail.", ERROR_INVALID_TYPE, 1);
		}
	}
	return (0);
}

static int	check_map(char *map, int lines)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error_handler("Error", ERROR_OPEN, 0);
	line = get_next_line(fd);
	if ()
	{
		free(line);
		ft_error_handler("Invalid map, it is not a rectangle.", ERROR_INVALID_TYPE, 1);		
	}		
	while(line)
	{
		check_wall(line, lines, i);
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

static int	check_filename(char *map)
{
	char *filename;

	filename = ft_strnstr(map, ".ber", ft_strlen(map));
	if (ft_strlen(filename) == 4)
		return (0);
	return (-1);
}

int	ft_isvalid(char *map)
{
	int		fd;
	int		lines;
	char	*line;

	if (check_filename(map) == -1)
		ft_error_handler("Invalid file type.", ERROR_INVALID_TYPE, 1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error_handler("Error", ERROR_OPEN, 0);
	if (read(fd, NULL, 0) == -1)
	{
		close(fd);
		ft_error_handler("Error", ERROR_READ, 0);
	}
	line = get_next_line(fd);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		lines++;
	}
	close(fd);
	return (check_map(map, lines));
}
