/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiators_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:44:48 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/25 16:13:56 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_init_null(t_data *data)
{
	data->img.wall_00 = NULL;
	data->img.wall_01 = NULL
	data->img.wall_1 = NULL;
	data->img.wall_2 = NULL;
	data->img.coll = NULL;
	data->img.player = NULL;
	data->img.player_1 = NULL;
	data->img.exit = NULL;
	data->img.empty = NULL;
}

void	image_init(t_data *data)
{
	int	size;

	size = PXL;
	data->img.wall_00 = mlx_xpm_file_to_image(data->mlx, WALL_00, &size, &size);
	data->img.wall_01 = mlx_xpm_file_to_image(data->mlx, WALL_01, &size, &size);
	data->img.wall_1 = mlx_xpm_file_to_image(data->mlx, WALL_1, &size, &size);
	data->img.wall_2 = mlx_xpm_file_to_image(data->mlx, WALL_2, &size, &size);
	data->img.coll = mlx_xpm_file_to_image(data->mlx, COLL, &size, &size);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER, &size, &size);
	data->img.player_1 = mlx_xpm_file_to_image(data->mlx, PLAYER_1, &size, &size);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT, &size, &size);
	data->img.empty = mlx_xpm_file_to_image(data->mlx, EMPTY, &size, &size);
}

void	data_init(t_data *data)
{
	data->width = 0;
	data->height = 1;
	data->pplayer_h = 0;
	data->pplayer_w = 0;
	data->p = 0;
	data->e = 0;
	data->c = 0;
	data->ff_e = 0;
	data->ff_c = 0;
	data->map = NULL;
	data->new_map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->size = 0;
	data->movements = 1;
	data->bag = 0;
	data->img = NULL;
}

void	all_init(t_data *data)
{
	int		width;
	int		height;

	data_init(data);
	image_init_null(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error_handler("Error", ERROR_MLX, NULL, &data);
	width = PXL * data->width;
	height = PXL * data->height;
	data->win = mlx_new_window(data.mlx, width, height, "Capybara World");
	if (!data->win)
		ft_error_handler("Error", ERROR_MLX, NULL, &data);	
}
