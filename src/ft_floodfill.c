/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:13:11 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/08 08:44:03 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(int **map, size_t size, int x, int y)
{
	if (x < 0 || x >= size[1] || y < 0 || y => size[0])
		return ;
	if (map[y][x] == '1')
		return ;
	
	map[y][x] = '1';

	floodFill(map, size x + 1, y);
    floodFill(map, size x - 1, y);
    floodFill(map, size x, y + 1);
    floodFill(map, size x, y - 1);	
}
