/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:14:55 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/31 23:39:58 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_image_init(t_data *data)
{
	int	len;

	len = PXL;
	data->player->frames[0] = mlx_xpm_file_to_image(data->mlx, PLAYER, &len, &len);
	data->player->frames[1] = mlx_xpm_file_to_image(data->mlx, PLAYER_1, &len, &len);
	data->player->frames[2] = NULL;
}

void	player_init(t_data *data)
{
	data->player->len_f = 3;
	data->player->pos_h = 0;
	data->player->pos_w = 0;
	data->player->current_frame = 0;
	data->player->frame_counter = 0;
	data->player->bag = 0;
	data->player->frames = (void *) malloc(data->player->len_f * sizeof(void *));
	if (!data->player->frames)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
}

void	player(t_data *data, int o_y, int o_x)
{
	// int	li;
	// int	col;

	// li = 0;
	// while (data->new_map[li])
	// {
	// 	col = 0;
	// 	while (data->new_map[li][col])
	// 	{
	// 		if (data->new_map[li][col] == 'C')
	// 			put_image(data, data->img->coll, col, li);
	// 		col++;
	// 	}
	// 	li++;
	// }
	put_image(data, data->player->frames[0], data->player->pos_w, data->player->pos_h);
	if (data->map[data->player->pos_h][data->player->pos_w] == 'E')
		put_image(data, data->player->frames[1], data->player->pos_w, data->player->pos_h);
	if (o_x && o_y)
	{
		put_image(data, data->background->frames[4], o_x, o_y);
		if (data->map[o_y][o_x] == 'E')
			put_image(data, data->background->frames[3], o_x, o_y);
	}
}
