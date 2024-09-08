/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:14:55 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/08 19:59:42 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_image_init(t_data *data)
{
	int	len;
	int	i;

	len = PXL;
	i = 0;
	data->plr->fr = (void *) malloc(data->plr->len_f * sizeof(void *));
	if (!data->plr->fr)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
	while (i < data->plr->len_f)
	{
		data->plr->fr[i] = NULL;
		i++;
	}
	data->plr->fr[0] = load_image(data, PLAYER, len);
	data->plr->fr[1] = load_image(data, PLAYER_1, len);
	data->plr->fr[2] = load_image(data, PLAYER_2, len);
}

void	player_init(t_data *data)
{
	data->plr->len_f = 4;
	data->plr->pos_h = 0;
	data->plr->pos_w = 0;
	data->plr->current_frame = 0;
	data->plr->frame_counter = 0;
	data->plr->bag = 0;
	data->plr->fr = NULL;
}

void	player(t_data *data, int o_y, int o_x)
{
	put_image(data, data->plr->fr[0], data->plr->pos_w, data->plr->pos_h);
	if (data->map[data->plr->pos_h][data->plr->pos_w] == 'E')
		put_image(data, data->plr->fr[1], data->plr->pos_w, data->plr->pos_h);
	if (o_x && o_y)
	{
		put_image(data, data->backg->fr[4], o_x, o_y);
		if (data->map[o_y][o_x] == 'E')
			put_image(data, data->backg->fr[3], o_x, o_y);
		if (data->map[o_y][o_x] == 'B')
			put_image(data, data->enm->fr[4], o_x, o_y);
	}
}
