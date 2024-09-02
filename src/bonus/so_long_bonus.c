/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/02 19:36:10 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	close_window(t_data *data)
{
	ft_error_handler(NULL, 0, NULL, data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}
int	animations(t_data *data)
{
	time_t	curr_time;

	curr_time = time(NULL);
	if (curr_time - data->move_time >= 1)
	{
		enemy(data); //verificar que as vezes tem delay na inicializacao
		data->move_time = curr_time;
	}
	collectibles(data);
	return (0);
}

static int	move(t_data *data, int y, int x)
{
	int	old_x;
	int	old_y;

	old_x = data->player->pos_w;
	old_y = data->player->pos_h;
	if (data->new_map[y][x] == '1')
		return (0);
	if (data->new_map[y][x] == 'C')
	{
		data->new_map[y][x] = '0';
		data->player->bag++;
	}
	data->player->pos_w = x;
	data->player->pos_h = y;
	data->new_map[old_y][old_x] = '0';
	data->new_map[y][x] = 'P';
	player(data, old_y, old_x);
	ft_printf("Move count: %d \n", data->movements);
	return (1);
}

static int	controller(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		data->movements += move(data, data->player->pos_h, data->player->pos_w - 1);
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		data->movements += move(data, data->player->pos_h, data->player->pos_w + 1);
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		data->movements += move(data, data->player->pos_h - 1, data->player->pos_w);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		data->movements += move(data, data->player->pos_h + 1, data->player->pos_w);
	if (data->map[data->player->pos_h][data->player->pos_w] == 'E')
	{
		if (data->c == data->player->bag)
		{
			ft_printf(" --- END ---");
			close_window(data);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	srand(time(NULL));
	if (argc == 2)
	{
		data = malloc(sizeof(t_data));
		if (!data)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, NULL);
		all_init(data, argv[1]);
		background(data);
		player(data, 0, 0);
		mlx_loop_hook(data->mlx, animations, data);
		mlx_hook(data->win, KeyPress, KeyPressMask, controller, data);
		mlx_hook(data->win, DestroyNotify, NoEventMask, close_window, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error_handler(strerror(EINVAL), ERROR_ARGUMENTS, NULL, NULL);
	return (0);
}
