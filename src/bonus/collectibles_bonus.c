/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:23:15 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/09 22:25:50 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collectibles_image_init(t_data *data)
{
	int	len;
	int	i;

	len = PXL;
	i = 0;
	data->collect->fr = (void *) malloc(data->collect->len_f * sizeof(void *));
	if (!data->collect->fr)
		close_window(data, 0);
	while (i < data->collect->len_f)
	{
		data->collect->fr[i] = NULL;
		i++;
	}
	data->collect->fr[0] = load_image(data, CRAB0, len);
	data->collect->fr[1] = load_image(data, CRAB1, len);
	data->collect->fr[2] = load_image(data, CRAB2, len);
	data->collect->fr[3] = load_image(data, CRAB3, len);
}

void	collectibles_init(t_data *data)
{
	data->collect->len_f = 5;
	data->collect->pos_h = 0;
	data->collect->pos_w = 0;
	data->collect->dir = 0;
	data->collect->current_frame = 0;
	data->collect->frame_counter = 0;
	data->collect->bag = 0;
	data->collect->fr = NULL;
}

void	put_animal(int col, int li, t_data *data)
{
	if (data->collect->current_frame == 0)
		put_image(data, data->collect->fr[0], col, li);
	if (data->collect->current_frame == 1)
		put_image(data, data->collect->fr[1], col, li);
	if (data->collect->current_frame == 2)
		put_image(data, data->collect->fr[2], col, li);
	if (data->collect->current_frame == 3)
		put_image(data, data->collect->fr[3], col, li);
}

void	collectibles(t_data *data)
{
	int	li;
	int	col;

	data->collect->frame_counter++;
	if (data->collect->frame_counter >= 1500)
	{
		data->collect->current_frame = (data->collect->current_frame + 1) % 4;
		data->collect->frame_counter = 0;
	}
	li = 0;
	while (data->map[li])
	{
		col = 0;
		while (data->map[li][col])
		{
			if (data->map[li][col] == 'C')
				put_animal(col, li, data);
			col++;
		}
		li++;
	}
}
