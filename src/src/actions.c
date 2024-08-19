/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:01:31 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/19 23:21:17 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_data *data)
{
	if (data->map[data->pplayer_h][data->pplayer_w - 1] == '1')
		return (0);
	put_empty(data);
	data->pplayer_w -= 1;
	put_player(data);
	return (1);
}

int	move_right(t_data *data)
{
	if (data->map[data->pplayer_h][data->pplayer_w + 1] == '1')
		return (0);
	put_empty(data);
	data->pplayer_w += 1;
	put_player(data);
	return (1);
}

int	move_up(t_data *data)
{
	if (data->map[data->pplayer_h - 1][data->pplayer_w] == '1')
		return (0);
	put_empty(data);
	data->pplayer_h -= 1;
	put_player(data);
	return (1);
}

int	move_down(t_data *data)
{
	if (data->map[data->pplayer_h + 1][data->pplayer_w] == '1')
		return (0);
	put_empty(data);
	data->pplayer_h += 1;
	put_player(data);
	return (1);
}
