/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/04 22:08:10 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Verifica se a extensa esta correta, se o arquivo existe e pode ser lido */
static int	ft_checkpathname(char *pathname)
{
	char	*filename;
	int		fd;

	filename = ft_strnstr(pathname, ".ber", ft_strlen(pathname));
	if (filename == NULL || ft_strlen(filename) != 4)
		ft_error_handler("Invalid file type.", ERROR_TYPE, 1, NULL);
	fd = ft_open(pathname);
	if (read(fd, NULL, 0) == -1)
	{
		close(fd);
		ft_error_handler("Error", ERROR_READ, 0, NULL);
	}
	return (fd);
}

/* Split de char de um str */
static void	put_point(char *str, int *map_line)
{
	int	i;

	i = 0;
	while(str[i])
	{
		map_line[i] = str[i];
		i++;
	}
}

static void	ft_createmap(char *pathname, int height, int **map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = ft_open(pathname);
	line = ft_strremove(get_next_line(fd), "\n");
	while(line && i < height)
	{
		put_point(line, map[i]);
		i++;
		free(line);
		line = ft_strremove(get_next_line(fd), "\n");
	}
	close(fd);
}

static int	ft_checkwall(char *line, size_t width, size_t height)
{
	size_t	i;

	i = 0;
	if (ft_strlen(line) != width)
		ft_error_handler("Invalid map, rectangle fail", ERROR_MAP, 1, line);	
	if (height == 1 || i == height - 1)
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
		if (line[0] != '1' || line[width - 1] != '1')
			ft_error_handler("Invalid map, wall fail", ERROR_MAP, 1, line);
	}
	return (0);
}

/* Retorna o tamanho do mapa em altura e largura */
static size_t	*ft_mapsize(int fd)
{
	char	*line;
	size_t	*size;

	size = (size_t *) malloc(2 * sizeof(size_t));
	if (!size)
		ft_error_handler("Error", ERROR_MALLOC, 0, NULL);
	size[0] = 1; //height
	line = ft_strremove(get_next_line(fd), "\n");
	size[1] = ft_strlen(line); //width
	while(line)
	{
		ft_checkwall(line, size[1], size[0]);
		free(line);
		line = ft_strremove(get_next_line(fd), "\n");
		if (!line)
			break ;
		size[0]++;
	}
	close(fd);
	if (size[0] <= 1 || size[1] <= 1)
		ft_error_handler("Invalid map, empty map", ERROR_MAP, 1, NULL);
	return (size);
}

int	ft_loadmap(char *pathname)
{
	size_t	*size;
	int		**map;
	int		fd;
	size_t		i = 0;

	fd = ft_checkpathname(pathname);
	size = ft_mapsize(fd);
	map = (int **) malloc(size[0] * sizeof(int *));
	while (i < size[0])
	{
		map[i] = (int *) malloc(size[1] * sizeof(int));
		if (!map[i])
			ft_error_handler("Error", ERROR_MALLOC, 0, NULL);
		i++; //verificar para resolver caso de erro no malloc
	}
	
	ft_createmap(pathname, size[0], map);
	ft_printf("-h-%d -w-%d\n", size[0], size[1]);
	
	//apenas para imprimir o mapa
	i = 0;
	size_t z;
	while (i < size[0])
	{
		z = 0;
		while (z < size[1])
			ft_printf("%c", map[i][z++]);
		ft_printf("\n");
		i++;
	}	
	return (0);
}
