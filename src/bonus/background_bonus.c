/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:58:04 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/04 22:41:03 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	background_image_init(t_data *data)
{
	int	len;

	len = PXL;
	data->background->frames[0] = mlx_xpm_file_to_image(data->mlx, WALL_0, &len, &len);
	data->background->frames[1] = mlx_xpm_file_to_image(data->mlx, WALL_1, &len, &len);
	data->background->frames[2] = mlx_xpm_file_to_image(data->mlx, WALL_2, &len, &len);
	data->background->frames[3] = mlx_xpm_file_to_image(data->mlx, EXIT, &len, &len);
	data->background->frames[4] = mlx_xpm_file_to_image(data->mlx, EMPTY, &len, &len);
	data->background->frames[5] = mlx_xpm_file_to_image(data->mlx, SHARK, &len, &len);
	data->background->frames[6] = NULL;
}

void	background_init(t_data *data)
{
	data->background->len_f = 7;
	data->background->pos_h = 0;
	data->background->pos_w = 0;
	data->background->current_frame = 0;
	data->background->frame_counter = 0;
	data->background->bag = 0;
	data->background->frames = (void **) malloc(data->background->len_f * sizeof(void *));
	if (!data->background->frames)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
}

void	shark(t_data *data)
{
	int	x;
	// int i = 0;

	x = data->background->current_frame;
	// while (i++ < data->width)
	// 	put_image(data, data->background->frames[0], x, data->height - 1);
	put_image(data, data->background->frames[5], x, data->height - 1);
	put_image(data, data->background->frames[0], x - 1, data->height - 1);
	// mlx_put_image_to_window(data->mlx, data->win, data->background->frames[5], x * 10,  (data->height - 1) * PXL);
	if (data->background->current_frame == data->width)
		data->background->current_frame = -1;
}

void	background(t_data *data)
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
					put_image(data, data->background->frames[0], col++, li);
				else if (col == 0 || col == data->width -1 || li == 0)
					put_image(data, data->background->frames[1], col++, li);
				else
					put_image(data, data->background->frames[2], col++, li);
			}
			else if (data->map[li][col] == 'E')
				put_image(data, data->background->frames[3], col++, li);
			else
				put_image(data, data->background->frames[4], col++, li);
		}
		li++;
	}
}
