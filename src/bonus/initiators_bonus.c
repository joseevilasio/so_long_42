/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiators_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:44:48 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/10 19:57:35 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	new_collectibles(t_data *data)
{
	int		li;
	int		col;
	int		new;
	char	*animals;

	li = 0;
	new = 0;
	animals = "CVN";
	while (data->map[li])
	{
		col = 0;
		while (data->map[li][col])
		{
			if (data->map[li][col] == 'C')
			{
				data->map[li][col] = animals[new];
				new++;
			}
			if (new == 3)
				new = 0;
			col++;
		}
		li++;
	}
}

void	data_init(t_data *data)
{
	data->width = 0;
	data->height = 1;
	data->p = 0;
	data->e = 0;
	data->c = 0;
	data->enemy_ = 0;
	data->ff_e = 0;
	data->ff_c = 0;
	data->map = NULL;
	data->new_map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->movements = 0;
	data->img_m = NULL;
	data->move_time = time(NULL);
	data->plr = (t_image *) malloc(sizeof(t_image));
	data->enm = (t_image *) malloc(sizeof(t_image));
	data->backg = (t_image *) malloc(sizeof(t_image));
	data->collect = (t_image *) malloc(sizeof(t_image));
	if (!data->plr || !data->enm || !data->backg || !data->collect)
		ft_error_handler("Error\n", ERROR_MALLOC, NULL, data);
}

void	all_init(t_data *data, char *path)
{
	int		width;
	int		height;

	data_init(data);
	enemy_init(data);
	background_init(data);
	player_init(data);
	collectibles_init(data);
	ft_loadmap(path, data);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error_handler("Error\n", ERROR_MLX, NULL, data);
	width = PXL * data->width;
	height = PXL * data->height;
	data->win = mlx_new_window(data->mlx, width, height, "Capybara World");
	if (!data->win)
		ft_error_handler("Error\n", ERROR_MLX, NULL, data);
	enemy_image_init(data);
	background_image_init(data);
	player_image_init(data);
	collectibles_image_init(data);
	new_collectibles(data);
}
