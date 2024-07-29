/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismapvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:47:14 by joneves-          #+#    #+#             */
/*   Updated: 2024/07/29 23:08:40 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall(char *wall, size_t lines, size_t i, size_t lenght_h)
{
	int	z;

	z = 0;
	if (ft_strlen(wall) == lenght_h && lenght_h > lines)
	{		
		if (i == 1 || i == lines)
		{
			while (wall[z])
			{
				if (wall[z] == '1' || wall[z] == '\n')
					z++;
				else
					ft_error_handler("Invalid map, wall fail", ERROR_INVALID_TYPE, 1, wall);
			}
		}
		else
		{
			if (wall[0] != '1' || wall[ft_strlen(wall) - 1] != '1')
				ft_error_handler("Invalid map, wall fail", ERROR_INVALID_TYPE, 1, wall);
		}
	}
	else
		ft_error_handler("Invalid map, rectangle fail", ERROR_INVALID_TYPE, 1, wall);
	return (0);
}

static int	check_map(char *map, size_t length_v)
{
	char	*line;
	size_t	i;
	int		fd;
	size_t	lenght_h;

	i = 1;
	fd = ft_open(map);
	line = ft_strremove(get_next_line(fd), "\n");
	lenght_h = ft_strlen(line);
	while(line)
	{
		check_wall(line, length_v, i, lenght_h);
		ft_printf("%s", line);
		free(line);
		line = ft_strremove(get_next_line(fd), "\n");
		i++;
	}
	close(fd);
	return (0);
}

// Verificar se a extensao do arquivo esta correta ".ber";
// Se e possivel abrir o arquivo no modo leitura;
// Se e possivel ler o arquivo.
static int	check_file(char *map)
{
	char	*filename;
	int		fd;

	filename = ft_strnstr(map, ".ber", ft_strlen(map));
	if (ft_strlen(filename) != 4)
		ft_error_handler("Invalid file type.", ERROR_INVALID_TYPE, 1, NULL);
	fd = ft_open(map);
	if (read(fd, NULL, 0) == -1)
	{
		close(fd);
		ft_error_handler("Error", ERROR_READ, 0, NULL);
	}
	close(fd);
	return (0);
}

static int	check_items(char *pathname)
{
	char	*line;
	int		fd;
	int		player;
	int		collectible;
	int		exit;

	player = 0;
	collectible = 0;
	exit = 0;
	fd = ft_open(pathname);
	line = get_next_line(fd);
	while(line)
	{
		if (ft_strchr(line, 'P'))
			player++;
		if (ft_strchr(line, 'C'))
			collectible++;
		if (ft_strchr(line, 'E'))
			exit++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (player != 1 || exit != 1 || collectible < 1)
		ft_error_handler("Invalid items.", ERROR_INVALID_TYPE, 1, NULL);
	return (0);
}

//criar funcao para popular map[width][height]
//refatorar as funcoes para utilizar o map
//implentar algoritmo flood fill

int	ft_ismapvalid(char *map)
{
	check_file(map);
	check_map(map, ft_countlines(map));
	check_items(map);
	//check_flood fill
	return (0);
}
