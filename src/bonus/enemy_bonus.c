/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:33:20 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/03 21:30:33 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_image_init(t_data *data)
{
	int	len;
	int	i;

	len = PXL;
	i = 0;
	while (i < data->enemy->len_f)
	{
		data->enemy->frames[i] = NULL;
		i++;
	}
	data->enemy->frames[0] = mlx_xpm_file_to_image(data->mlx, EB0, &len, &len);
	data->enemy->frames[1] = mlx_xpm_file_to_image(data->mlx, EB1, &len, &len);
	data->enemy->frames[2] = mlx_xpm_file_to_image(data->mlx, EB2, &len, &len);
	data->enemy->frames[3] = mlx_xpm_file_to_image(data->mlx, EF0, &len, &len);
	data->enemy->frames[4] = mlx_xpm_file_to_image(data->mlx, EF1, &len, &len);
	data->enemy->frames[5] = mlx_xpm_file_to_image(data->mlx, EF2, &len, &len);
	data->enemy->frames[6] = mlx_xpm_file_to_image(data->mlx, EL0, &len, &len);
	data->enemy->frames[7] = mlx_xpm_file_to_image(data->mlx, EL1, &len, &len);
	data->enemy->frames[8] = mlx_xpm_file_to_image(data->mlx, EL2, &len, &len);
	data->enemy->frames[9] = mlx_xpm_file_to_image(data->mlx, ER0, &len, &len);
	data->enemy->frames[10] = mlx_xpm_file_to_image(data->mlx, ER1, &len, &len);
	data->enemy->frames[11] = mlx_xpm_file_to_image(data->mlx, ER2, &len, &len);
	data->enemy->frames[12] = mlx_xpm_file_to_image(data->mlx, BLL, &len, &len);
	data->enemy->frames[13] = NULL;
}

void	enemy_init(t_data *data)
{
	data->enemy->len_f = 14;
	data->enemy->pos_h = 0;
	data->enemy->pos_w = 0;
	data->enemy->current_frame = 0;
	data->enemy->frame_counter = 0;
	data->enemy->bag = 0;
	data->enemy->frames = (void **) malloc(data->enemy->len_f * sizeof(void *));
	if (!data->enemy->frames)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
}

void	enemy_render(t_data *data, int o_y, int o_x, int dir)
{
	if (dir == LEFT)
	{
		//put_image(data, data->img->eleft0, data->penemy_w, data->penemy_h);
		//put_image(data, data->img->eleft1, data->penemy_w, data->penemy_h);
		put_image(data, data->enemy->frames[8], data->enemy->pos_w, data->enemy->pos_h);
	}
	if (dir == RIGHT)
	{
		//put_image(data, data->img->eright0, data->penemy_w, data->penemy_h);
		//put_image(data, data->img->eright1, data->penemy_w, data->penemy_h);
		put_image(data, data->enemy->frames[11], data->enemy->pos_w, data->enemy->pos_h);
	}
	if (dir == UP)
	{
		//put_image(data, data->img->eback0, data->penemy_w, data->penemy_h);
		//put_image(data, data->img->eback1, data->penemy_w, data->penemy_h);
		put_image(data, data->enemy->frames[2], data->enemy->pos_w, data->enemy->pos_h);
	}
	if (dir == DOWN)
	{
		//put_image(data, data->img->efront0, data->penemy_w, data->penemy_h);
		//put_image(data, data->img->efront1, data->penemy_w, data->penemy_h);
		put_image(data, data->enemy->frames[5], data->enemy->pos_w, data->enemy->pos_h);
	}
	if (o_x && o_y)
	{
		if (data->map[o_y][o_x] == 'E')
			put_image(data, data->background->frames[3], o_x, o_y);
		else if (data->new_map[o_y][o_x] == 'B')
			put_image(data, data->enemy->frames[12],  o_x, o_y);
		else
			put_image(data, data->background->frames[4], o_x, o_y);
	}
}

int	enemy_move(t_data *data, int y, int x, int dir)
{
	int	old_x;
	int	old_y;

	old_x = data->enemy->pos_w;
	old_y = data->enemy->pos_h;
	if (data->new_map[y][x] == '1')
		return (0);
	if (data->new_map[y][x] == 'C')
		data->enemy->bag++;
	data->enemy->pos_w = x;
	data->enemy->pos_h = y;
	if (data->map[old_y][old_x] == 'C')
		data->new_map[old_y][old_x] = 'B';
	else
		data->new_map[old_y][old_x] = '0';
	data->new_map[y][x] = 'A';
	ft_printmap(data->new_map);
	enemy_render(data, old_y, old_x, dir);
	return (1);
}

int	enemy(t_data *data)
{
	int	dir;

	dir = rand() % 4;
	if (dir == LEFT)
		enemy_move(data, data->enemy->pos_h, data->enemy->pos_w - 1, dir);
	if (dir == RIGHT)
		enemy_move(data, data->enemy->pos_h, data->enemy->pos_w + 1, dir);
	if (dir == UP)
		enemy_move(data, data->enemy->pos_h - 1, data->enemy->pos_w, dir);
	if (dir == DOWN)
		enemy_move(data, data->enemy->pos_h + 1, data->enemy->pos_w, dir);
	// if (data->new_map[data->enemy->pos_h][data->enemy->pos_w] == 'P')
	// {
	// 	ft_printf(" --- END ---");
	// 	close_window(data);
	// }
	return (0);
}
