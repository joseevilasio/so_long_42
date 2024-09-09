/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:58:04 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/09 22:27:06 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	background_image_init(t_data *data)
{
	int	len;
	int	i;

	len = PXL;
	i = 0;
	data->backg->fr = (void *) malloc(data->backg->len_f * sizeof(void *));
	if (!data->backg->fr)
		close_window(data, 0);
	while (i < data->backg->len_f)
	{
		data->backg->fr[i] = NULL;
		i++;
	}
	data->backg->fr[0] = load_image(data, WALL_0, len);
	data->backg->fr[1] = load_image(data, WALL_1, len);
	data->backg->fr[2] = load_image(data, WALL_2, len);
	data->backg->fr[3] = load_image(data, EXIT, len);
	data->backg->fr[4] = load_image(data, EMPTY, len);
	data->backg->fr[5] = load_image(data, SHARK, len);
	data->backg->fr[6] = load_image(data, COUNT, len);
}

void	background_init(t_data *data)
{
	data->backg->len_f = 8;
	data->backg->pos_h = 0;
	data->backg->pos_w = 0;
	data->backg->dir = 0;
	data->backg->current_frame = 0;
	data->backg->frame_counter = 0;
	data->backg->bag = 0;
	data->backg->fr = NULL;
}

void	shark(t_data *data)
{
	int	x;

	x = data->backg->current_frame;
	put_image(data, data->backg->fr[5], x, data->height - 1);
	put_image(data, data->backg->fr[0], x - 1, data->height - 1);
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
					put_image(data, data->backg->fr[0], col++, li);
				else if (col == 0 || col == data->width -1 || li == 0)
					put_image(data, data->backg->fr[1], col++, li);
				else
					put_image(data, data->backg->fr[2], col++, li);
			}
			else if (data->map[li][col] == 'E')
				put_image(data, data->backg->fr[3], col++, li);
			else
				put_image(data, data->backg->fr[4], col++, li);
		}
		li++;
	}
}
