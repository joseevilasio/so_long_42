/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:47:34 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/18 14:39:43 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_render(void *mlx, void *window, char **map, int map_width, int map_height)
{
	int cell_width = 80;
	int cell_height = 80;
	void *wall_texture = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &cell_width, &cell_height);
	void *collectable_texture = mlx_xpm_file_to_image(mlx, "./textures/coletavel.xpm", &cell_width, &cell_height);
	void *player_texture = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &cell_width, &cell_height);
	void *exit_texture = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", &cell_width, &cell_height);
	void *empty_texture = mlx_xpm_file_to_image(mlx, "./textures/space.xpm", &cell_width, &cell_height);
	int	line;
	int	column;
	int x;
	int y;

	line = 0;
	while (line < map_height)
	{
		column = 0;
		while (column < map_width)
		{
			x = column * cell_width;
			y = line * cell_height;
			
			if (map[line][column] == '1')
				mlx_put_image_to_window(mlx, window, wall_texture, x, y);
			else if (map[line][column] == 'C')
				mlx_put_image_to_window(mlx, window, collectable_texture, x, y);
			else if (map[line][column] == 'P')
				mlx_put_image_to_window(mlx, window, player_texture, x, y);
			else if (map[line][column] == 'E')
				mlx_put_image_to_window(mlx, window, exit_texture, x, y);
			else
				mlx_put_image_to_window(mlx, window, empty_texture, x, y);
			column++;
		}
		line++;
	}
}
