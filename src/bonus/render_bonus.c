/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:47:34 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/25 15:45:03 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_data *data, void *img, int column, int line)
{
	int	x;
	int	y;

	x = column * PXL;
	y = line * PXL;
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
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
