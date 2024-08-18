/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/18 23:01:20 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_error_handler(NULL, 0, NULL, data);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

int	action_up(void)
{
	ft_printf("UP");
	return (0);
}

static int	controller(t_data *data)
{
	mlx_key_hook(data->win, action_up, NULL);
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
		data.win = mlx_new_window(data.mlx, (80*data.width), (80*data.height), "so_long");
		ft_render_background(&data);
		mlx_loop_hook(data.mlx, controller, &data);
		mlx_key_hook(data.win, close_window, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_error_handler(strerror(EINVAL), ERROR_ARGUMENTS, NULL, NULL);
	return (0);		
}
