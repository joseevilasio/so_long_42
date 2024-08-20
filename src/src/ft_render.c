/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:47:34 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/20 20:26:43 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_init(t_data *data)
{
	int	size;

	size = PIXEL;
	data->img_size = size;
	data->img_wall = mlx_xpm_file_to_image(data->mlx, WALL, &size, &size);
	data->img_coll = mlx_xpm_file_to_image(data->mlx, COLL, &size, &size);
	data->img_player = mlx_xpm_file_to_image(data->mlx, PLAYER, &size, &size);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, EXIT, &size, &size);
	data->img_empty = mlx_xpm_file_to_image(data->mlx, EMPTY, &size, &size);
}

void	ft_render_background(t_data *data)
{
	int	line;
	int	column;
	int x;
	int y;

	line = 0;
	ft_image_init(data);
	while (data->map[line])
	{
		column = 0;	
		while (data->map[line][column])
		{
			x = column * data->img_size;
			y = line * data->img_size;
			if (data->map[line][column] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x, y);
			else if (data->map[line][column] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x, y);
			else
				mlx_put_image_to_window(data->mlx, data->win, data->img_empty, x, y);
			column++;
		}
		line++;
	}
}

void	ft_render_layer(t_data *data)
{
	int	line;
	int	column;
	int x;
	int y;

	line = 0;
	while (data->map[line])
	{
		column = 0;	
		while (data->map[line][column])
		{
			x = column * data->img_size;
			y = line * data->img_size;
			if (data->new_map[line][column] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img_coll, x, y);
			else if (data->new_map[line][column] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img_player, x, y);
			else if (data->map[line][column] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x, y);
			column++;
		}
		line++;
	}
}

void	put_player(t_data *data)
{
	int	x;
	int	y;

	x = data->pplayer_w * data->img_size;
	y = data->pplayer_h * data->img_size;
	mlx_put_image_to_window(data->mlx, data->win, data->img_player, x, y);
}

void	put_empty(t_data *data, char set)
{
	int	x;
	int	y;

	x = data->pplayer_w * data->img_size;
	y = data->pplayer_h * data->img_size;
	if (set == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img_empty, x, y);
}
