/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:58:04 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/06 20:48:24 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	background_image_init(t_data *data)
{
	int	len;

	len = PXL;
	data->backg->frames[0] = mlx_xpm_file_to_image(data->mlx, WALL_0, &len, &len);
	data->backg->frames[1] = mlx_xpm_file_to_image(data->mlx, WALL_1, &len, &len);
	data->backg->frames[2] = mlx_xpm_file_to_image(data->mlx, WALL_2, &len, &len);
	data->backg->frames[3] = mlx_xpm_file_to_image(data->mlx, EXIT, &len, &len);
	data->backg->frames[4] = mlx_xpm_file_to_image(data->mlx, EMPTY, &len, &len);
	data->backg->frames[5] = mlx_xpm_file_to_image(data->mlx, SHARK, &len, &len);
	data->backg->frames[6] = NULL;
}

void	background_init(t_data *data)
{
	data->backg->len_f = 7;
	data->backg->pos_h = 0;
	data->backg->pos_w = 0;
	data->backg->current_frame = 0;
	data->backg->frame_counter = 0;
	data->backg->bag = 0;
	data->backg->frames = (void **) malloc(data->backg->len_f * sizeof(void *));
	if (!data->backg->frames)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
}

void	shark(t_data *data)
{
	int	x;
	// int i = 0;

	x = data->backg->current_frame;
	put_image(data, data->backg->frames[5], x, data->height - 1);
	put_image(data, data->backg->frames[0], x - 1, data->height - 1);
	if (data->backg->current_frame == data->width)
		data->backg->current_frame = -1;
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
					put_image(data, data->backg->frames[0], col++, li);
				else if (col == 0 || col == data->width -1 || li == 0)
					put_image(data, data->backg->frames[1], col++, li);
				else
					put_image(data, data->backg->frames[2], col++, li);
			}
			else if (data->map[li][col] == 'E')
				put_image(data, data->backg->frames[3], col++, li);
			else
				put_image(data, data->backg->frames[4], col++, li);
		}
		li++;
	}
}
