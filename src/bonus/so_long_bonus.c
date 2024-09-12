/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/12 19:08:39 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_data *data, int mode)
{
	if (mode == 1)
	{
		ft_printf("\n --- END ---\n");
		if (data->plr->bag > data->enm->bag)
			ft_printf("\n --- CAPYBARA WIN'S ---\n");
		else
			ft_printf("\n --- ASH WIN'S ---\n");
	}
	if (mode == 2)
		ft_printf("\n --- ASH WIN'S ---\n");
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
	if (data->enm->current_frame == 0)
		put_image(data, data->enm->fr[0], data->enm->pos_w, data->enm->pos_h);
	if (curr_time - data->move_time >= 1)
	{
		if (data->enm->pos_h != 0)
			enemy(data);
		shark(data);
		data->backg->current_frame++;
		data->move_time = curr_time;
	}
	collectibles(data);
	return (0);
}

static int	move(t_data *data, int y, int x)
{
	int	old_x;
	int	old_y;

	old_x = data->plr->pos_w;
	old_y = data->plr->pos_h;
	if (data->new_map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'C' || data->map[y][x] == 'V'
		|| data->map[y][x] == 'N')
	{
		data->map[y][x] = '0';
		data->plr->bag++;
	}
	data->plr->pos_w = x;
	data->plr->pos_h = y;
	data->new_map[old_y][old_x] = '0';
	if (data->new_map[y][x] == 'A')
		close_window(data, 2);
	data->new_map[y][x] = 'P';
	if (data->movements == 0)
		data->movements++;
	player(data, old_y, old_x);
	put_move(data);
	return (1);
}

static int	controller(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data, 0);
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
	{
		data->plr->dir = 1;
		data->movements += move(data, data->plr->pos_h, data->plr->pos_w - 1);
	}
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
	{
		data->plr->dir = 0;
		data->movements += move(data, data->plr->pos_h, data->plr->pos_w + 1);
	}
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		data->movements += move(data, data->plr->pos_h - 1, data->plr->pos_w);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		data->movements += move(data, data->plr->pos_h + 1, data->plr->pos_w);
	if ((data->map[data->plr->pos_h][data->plr->pos_w] == 'E'
		&& data->c == (data->plr->bag + data->enm->bag)))
	{
		close_window(data, 1);
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
		put_move(data);
		mlx_loop_hook(data->mlx, animations, data);
		mlx_hook(data->win, KeyPress, KeyPressMask, controller, data);
		mlx_hook(data->win, DestroyNotify, NoEventMask, close_window, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error_handler(strerror(EINVAL), ERROR_ARGUMENTS, NULL, NULL);
	return (0);
}
