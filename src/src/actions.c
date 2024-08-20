/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:01:31 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/20 19:52:10 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//atualizar para receber apenas x e y direto do controller
int	move_left(t_data *data)
{
	char	set;

	set = '0';
	if (data->new_map[data->pplayer_h][data->pplayer_w - 1] == '1')
		return (0);
	if (data->new_map[data->pplayer_h][data->pplayer_w - 1] == 'C')
	{
		data->new_map[data->pplayer_h][data->pplayer_w - 1] = '0';
		data->bag++;
	}
	if (data->new_map[data->pplayer_h][data->pplayer_w - 1] == 'E')
		set = 'E';
	put_empty(data, set); //talvez receber img que tem nessa posicao, apagar e depois renderizar a nova
	data->pplayer_w -= 1;
	// data->new_map[data->pplayer_h][data->pplayer_w - 1] = 'P'; //ainda nao atualizando Player no mapa
	put_player(data);
	if(data->c == data->bag && set == 'E')
	{
		ft_printf("The End");
		close_window(data);
	}
	return (1);
}

int	move_right(t_data *data)
{
	char	set;

	set = '0';
	if (data->new_map[data->pplayer_h][data->pplayer_w + 1] == '1')
		return (0);
	if (data->new_map[data->pplayer_h][data->pplayer_w + 1] == 'C')
	{
		data->new_map[data->pplayer_h][data->pplayer_w + 1] = '0';
		data->bag++;
	}
	if (data->new_map[data->pplayer_h][data->pplayer_w + 1] == 'E')
		set = 'E';
	put_empty(data, set); //talvez receber img que tem nessa posicao, apagar e depois renderizar a nova
	data->pplayer_w += 1;
	// data->new_map[data->pplayer_h][data->pplayer_w - 1] = 'P'; //ainda nao atualizando Player no mapa
	put_player(data);
	if(data->c == data->bag && set == 'E')
	{
		ft_printf("The End");
		close_window(data);
	}
	return (1);
}

int	move_up(t_data *data)
{
	char	set;

	set = '0';
	if (data->new_map[data->pplayer_h - 1][data->pplayer_w] == '1')
		return (0);
	if (data->new_map[data->pplayer_h - 1][data->pplayer_w] == 'C')
	{
		data->new_map[data->pplayer_h - 1][data->pplayer_w] = '0';
		data->bag++;
	}
	if (data->new_map[data->pplayer_h - 1][data->pplayer_w] == 'E')
		set = 'E';
	put_empty(data, set); //talvez receber img que tem nessa posicao, apagar e depois renderizar a nova
	data->pplayer_h -= 1;
	// data->new_map[data->pplayer_h][data->pplayer_w - 1] = 'P'; //ainda nao atualizando Player no mapa
	put_player(data);
	if(data->c == data->bag && set == 'E')
	{
		ft_printf("The End");
		close_window(data);
	}
	return (1);
}

int	move_down(t_data *data)
{
	char	set;

	set = '0';
	if (data->new_map[data->pplayer_h + 1][data->pplayer_w] == '1')
		return (0);
	if (data->new_map[data->pplayer_h + 1][data->pplayer_w] == 'C')
	{
		data->new_map[data->pplayer_h + 1][data->pplayer_w] = '0';
		data->bag++;
	}
	if (data->new_map[data->pplayer_h + 1][data->pplayer_w] == 'E')
		set = 'E';
	put_empty(data, set); //talvez receber img que tem nessa posicao, apagar e depois renderizar a nova
	data->pplayer_h += 1;
	// data->new_map[data->pplayer_h][data->pplayer_w - 1] = 'P'; //ainda nao atualizando Player no mapa
	put_player(data);
	if(data->c == data->bag && set == 'E')
	{
		ft_printf("The End");
		close_window(data);
	}
	return (1);
}
