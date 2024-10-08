/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/31 21:32:05 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_data *data)
{
	ft_error_handler(NULL, 0, NULL, data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

static int	move(t_data *data, int y, int x)
{
	int	old_x;
	int	old_y;

	old_x = data->pplayer_w;
	old_y = data->pplayer_h;
	if (data->new_map[y][x] == '1')
		return (0);
	if (data->new_map[y][x] == 'C')
	{
		data->new_map[y][x] = '0';
		data->bag++;
	}
	data->pplayer_w = x;
	data->pplayer_h = y;
	data->new_map[old_y][old_x] = '0';
	data->new_map[y][x] = 'P';
	ft_render_layer(data, old_y, old_x);
	ft_printf("Move count: %d \n", data->movements);
	return (1);
}

static int	controller(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		data->movements += move(data, data->pplayer_h, data->pplayer_w - 1);
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		data->movements += move(data, data->pplayer_h, data->pplayer_w + 1);
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		data->movements += move(data, data->pplayer_h - 1, data->pplayer_w);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		data->movements += move(data, data->pplayer_h + 1, data->pplayer_w);
	if (data->map[data->pplayer_h][data->pplayer_w] == 'E')
	{
		if (data->c == data->bag)
		{
			ft_printf(" --- END ---");
			close_window(data);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		width;
	int		height;

	if (argc == 2)
	{
		ft_loadmap(argv[1], &data);
		data.mlx = mlx_init();
		if (!data.mlx)
			ft_error_handler("Error\n", ERROR_MLX, NULL, &data);
		width = PXL * data.width;
		height = PXL * data.height;
		data.win = mlx_new_window(data.mlx, width, height, "so_long");
		ft_image_init(&data);
		ft_render_background(&data);
		ft_render_layer(&data, 0, 0);
		mlx_hook(data.win, KeyPress, KeyPressMask, controller, &data);
		mlx_hook(data.win, DestroyNotify, NoEventMask, close_window, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_error_handler(strerror(EINVAL), ERROR_ARGUMENTS, NULL, NULL);
	return (0);
}
