/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:47:34 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/25 14:45:42 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, void *img, int column, int line)
{
	int	x;
	int	y;

	x = column * PXL;
	y = line * PXL;
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}

void	ft_image_init(t_data *data)
{
	int	size;

	size = PXL;
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL_0, &size, &size);
	data->wall_1 = mlx_xpm_file_to_image(data->mlx, WALL_1, &size, &size);
	data->wall_2 = mlx_xpm_file_to_image(data->mlx, WALL_2, &size, &size);
	data->coll = mlx_xpm_file_to_image(data->mlx, COLL, &size, &size);
	data->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &size, &size);
	data->player_1 = mlx_xpm_file_to_image(data->mlx, PLAYER_1, &size, &size);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &size, &size);
	data->empty = mlx_xpm_file_to_image(data->mlx, EMPTY, &size, &size);
}

void	ft_render_background(t_data *data)
{
	int	li;
	int	col;

	li = 0;
	while (data->map[li])
	{
		col = 0;
		while (data->map[li][col])
		{
			if (data->map[li][col] == '1')
			{
				if (li == data->height -1)
					put_image(data, data->wall, col++, li);
				else if (col == 0 || col == data->width -1 || li == 0)
					put_image(data, data->wall_1, col++, li);
				else
					put_image(data, data->wall_2, col++, li);
			}
			else if (data->map[li][col] == 'E')
				put_image(data, data->exit, col++, li);
			else
				put_image(data, data->empty, col++, li);
		}
		li++;
	}
}

void	ft_render_layer(t_data *data, int o_y, int o_x)
{
	int	li;
	int	col;

	li = 0;
	while (data->new_map[li])
	{
		col = 0;
		while (data->new_map[li][col])
		{
			if (data->new_map[li][col] == 'C')
				put_image(data, data->coll, col, li);
			col++;
		}
		li++;
	}
	put_image(data, data->player, data->pplayer_w, data->pplayer_h);
	if (data->map[data->pplayer_h][data->pplayer_w] == 'E')
		put_image(data, data->player_1, data->pplayer_w, data->pplayer_h);
	if (o_x && o_y)
	{
		put_image(data, data->empty, o_x, o_y);
		if (data->map[o_y][o_x] == 'E')
			put_image(data, data->exit, o_x, o_y);
	}
}
