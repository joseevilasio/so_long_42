/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:33:20 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/30 20:17:35 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy(t_data *data, int y, int x)
{
	int	old_x;
	int	old_y;

	old_x = data->penemy_w;
	old_y = data->penemy_h;
	if (data->new_map[y][x] == '1')
		return (0);
	// if (data->new_map[y][x] == 'C')
	// {
	// 	data->new_map[y][x] = '0';
	// 	data->bag++;
	// }
	data->penemy_w = x;
	data->penemy_h = y;
	data->new_map[old_y][old_x] = '0';
	data->new_map[y][x] = 'A';
	ft_render_layer(data, old_y, old_x);
	return (1);
}

int	enemy(t_data *data)
{
	int	dir;

	dir = rand() % 4;
	if (dir == LEFT)
		move_enemy(data, data->penemy_h, data->penemy_w - 1);
	if (dir == RIGHT)
		move_enemy(data, data->penemy_h, data->penemy_w + 1);
	if (dir == UP)
		move_enemy(data, data->penemy_h - 1, data->penemy_w);
	if (dir == DOWN)
		move_enemy(data, data->penemy_h + 1, data->penemy_w);
	// if (data->new_map[data->pplayer_h][data->pplayer_w] == 'P')
	// {
	// 	if (data->c == data->bag)
	// 	{
	// 		ft_printf(" --- END ---");
	// 		close_window(data);
	// 	}
	// }
	return (0);
}
