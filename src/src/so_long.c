/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/19 21:29:02 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_window(t_data *data)
{
	ft_error_handler(NULL, 0, NULL, data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

static int	controller(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		data->movements += move_left(data);
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		data->movements += move_right(data);
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		data->movements += move_up(data);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		data->movements += move_down(data);
	ft_printf("Move count: %d\n", data->movements);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		ft_loadmap(argv[1], &data); //considerar uma struct para receber o map e ter funcao init map
		data.mlx = mlx_init();
		if (!data.mlx)
			ft_error_handler("Error", ERROR_MLX, NULL, &data);
		data.win = mlx_new_window(data.mlx, (PIXEL*data.width), (PIXEL*data.height), "so_long");
		ft_render_background(&data);
		mlx_hook(data.win, KeyPress, KeyPressMask, controller, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_error_handler(strerror(EINVAL), ERROR_ARGUMENTS, NULL, NULL);
	return (0);		
}
	