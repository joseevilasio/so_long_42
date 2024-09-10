/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:23:15 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/10 19:49:07 by joneves-         ###   ########.fr       */
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
	data->collect->fr[4] = load_image(data, BIRD, len);
	data->collect->fr[5] = load_image(data, COW, len);
	data->collect->fr[6] = load_image(data, APPLE, len);
}

void	collectibles_init(t_data *data)
{
	data->collect->len_f = 8;
	data->collect->pos_h = 0;
	data->collect->pos_w = 0;
	data->collect->dir = 0;
	data->collect->current_frame = 0;
	data->collect->frame_counter = 0;
	data->collect->bag = 0;
	data->collect->fr = NULL;
}

void	put_animal(int col, int li, t_data *data, char animal)
{
	if (data->collect->current_frame == 0 && animal == 'C')
		put_image(data, data->collect->fr[0], col, li);
	if (data->collect->current_frame == 1 && animal == 'C')
		put_image(data, data->collect->fr[1], col, li);
	if (data->collect->current_frame == 2 && animal == 'C')
		put_image(data, data->collect->fr[2], col, li);
	if (data->collect->current_frame == 3 && animal == 'C')
		put_image(data, data->collect->fr[3], col, li);
	if (/* data->collect->current_frame == 0 && */ animal == 'V')
		put_image(data, data->collect->fr[4], col, li);
	/* if (data->collect->current_frame == 1 && animal == 'V')
		put_image(data, data->collect->fr[5], col, li);
	if (data->collect->current_frame == 2 && animal == 'V')
		put_image(data, data->collect->fr[6], col, li);
	if (data->collect->current_frame == 3 && animal == 'V')
		put_image(data, data->collect->fr[7], col, li); */
	if (/* data->collect->current_frame == 0 && */ animal == 'N')
		put_image(data, data->collect->fr[5], col, li);
/* 	if (data->collect->current_frame == 1 && animal == 'N')
		put_image(data, data->collect->fr[9], col, li);
	if (data->collect->current_frame == 2 && animal == 'N')
		put_image(data, data->collect->fr[10], col, li);
	if (data->collect->current_frame == 3 && animal == 'N')
		put_image(data, data->collect->fr[11], col, li); */
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
				put_animal(col, li, data, 'C');
			if (data->map[li][col] == 'V')
				put_animal(col, li, data, 'V');
			if (data->map[li][col] == 'N')
				put_animal(col, li, data, 'N');
			col++;
		}
		li++;
	}
}
