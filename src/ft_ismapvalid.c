/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismapvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:47:14 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/04 14:54:44 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkitems(char *pathname)
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

// int	ft_ismapvalid(char *map)
// {
// 	check_file(map);
// 	check_map(map, ft_countlines(map));
// 	check_items(map);
// 	//check_flood fill
// 	return (0);
// }
