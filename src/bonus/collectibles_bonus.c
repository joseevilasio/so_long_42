/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:23:15 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/06 20:58:43 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collectibles_image_init(t_data *data)
{
	int	len;

	len = PXL;
	data->collect->frames[0] = mlx_xpm_file_to_image(data->mlx, CRAB0, &len, &len);
	data->collect->frames[1] = mlx_xpm_file_to_image(data->mlx, CRAB1, &len, &len);
    data->collect->frames[2] = mlx_xpm_file_to_image(data->mlx, CRAB2, &len, &len);
    data->collect->frames[3] = mlx_xpm_file_to_image(data->mlx, CRAB3, &len, &len);
	data->collect->frames[4] = NULL;
}

void	collectibles_init(t_data *data)
{
	data->collect->len_f = 5;
	data->collect->pos_h = 0;
	data->collect->pos_w = 0;
	data->collect->current_frame = 0;
	data->collect->frame_counter = 0;
	data->collect->bag = 0;
	data->collect->frames = (void *) malloc(data->collect->len_f * sizeof(void *));
	if (!data->collect->frames)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
}

void	put_animal(int col, int li, t_data *data)
{
	if (data->collect->current_frame == 0)
		put_image(data, data->collect->frames[0], col, li);
	if (data->collect->current_frame == 1)
		put_image(data, data->collect->frames[1], col, li);
	if (data->collect->current_frame == 2)
		put_image(data, data->collect->frames[2], col, li);
	if (data->collect->current_frame == 3)
		put_image(data, data->collect->frames[3], col, li);
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
