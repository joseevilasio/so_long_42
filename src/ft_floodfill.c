/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:13:11 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/11 14:12:40 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(int **map, t_init *map_init, int x, int y)
{
	if (x < 0 || x >= map_init->size[1] || y < 0 || y >= map_init->size[0])
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		map_init->ff_e++;
	if (map[y][x] == 'C')
		map_init->ff_c++;
	map[y][x] = '1';
	ft_floodfill(map, map_init, x + 1, y);
	ft_floodfill(map, map_init, x - 1, y);
	ft_floodfill(map, map_init, x, y + 1);
	ft_floodfill(map, map_init, x, y - 1);
}
