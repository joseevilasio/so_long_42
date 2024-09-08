/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:33:20 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/08 20:07:02 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_image_init(t_data *data)
{
	int	len;
	int	i;

	len = PXL;
	i = 0;
	data->enm->fr = (void *) malloc(data->enm->len_f * sizeof(void *));
	if (!data->enm->fr)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
	while (i < data->enm->len_f)
	{
		data->enm->fr[i] = NULL;
		i++;
	}
	data->enm->fr[0] = load_image(data, EB1, len);
	data->enm->fr[1] = load_image(data, EF1, len);
	data->enm->fr[2] = load_image(data, EL1, len);
	data->enm->fr[3] = load_image(data, ER1, len);
	data->enm->fr[4] = load_image(data, BLL, len);
}

void	enemy_init(t_data *data)
{
	data->enm->len_f = 6;
	data->enm->pos_h = 0;
	data->enm->pos_w = 0;
	data->enm->current_frame = 0;
	data->enm->frame_counter = 0;
	data->enm->bag = 0;
	data->enm->fr = NULL;
}

void	enemy_render(t_data *data, int o_y, int o_x, int dir)
{
	if (dir == LEFT)
		put_image(data, data->enm->fr[2], data->enm->pos_w, data->enm->pos_h);
	if (dir == RIGHT)
		put_image(data, data->enm->fr[3], data->enm->pos_w, data->enm->pos_h);
	if (dir == UP)
		put_image(data, data->enm->fr[0], data->enm->pos_w, data->enm->pos_h);
	if (dir == DOWN)
		put_image(data, data->enm->fr[1], data->enm->pos_w, data->enm->pos_h);
	if (o_x && o_y)
	{
		if (data->map[o_y][o_x] == 'E')
			put_image(data, data->backg->fr[3], o_x, o_y);
		else if (data->map[o_y][o_x] == 'B')
			put_image(data, data->enm->fr[4], o_x, o_y);
		else
			put_image(data, data->backg->fr[4], o_x, o_y);
	}
}

int	enemy_move(t_data *data, int y, int x, int dir)
{
	int	old_x;
	int	old_y;

	old_x = data->enm->pos_w;
	old_y = data->enm->pos_h;
	if (data->new_map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = 'B';
		data->enm->bag++;
	}
	data->enm->pos_w = x;
	data->enm->pos_h = y;
	data->new_map[old_y][old_x] = '0';
	if (data->new_map[y][x] == 'P')
		close_window(data, 2);
	data->new_map[y][x] = 'A';
	enemy_render(data, old_y, old_x, dir);
	return (1);
}

int	enemy(t_data *data)
{
	int	dir;

	dir = rand() % 4;
	if (dir == LEFT)
		enemy_move(data, data->enm->pos_h, data->enm->pos_w - 1, dir);
	if (dir == RIGHT)
		enemy_move(data, data->enm->pos_h, data->enm->pos_w + 1, dir);
	if (dir == UP)
		enemy_move(data, data->enm->pos_h - 1, data->enm->pos_w, dir);
	if (dir == DOWN)
		enemy_move(data, data->enm->pos_h + 1, data->enm->pos_w, dir);
	return (0);
}
