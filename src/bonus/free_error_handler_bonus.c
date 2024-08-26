/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:55:58 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/26 19:52:57 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_handler(char *error, int signal, char *str, t_data *data)
{
	if (signal >= 100 && signal < 200)
	{
		if (str)
			free(str);
		if (data)
			ft_free_data(data);
		perror(error);
		exit (signal);
	}
	else if (signal >= 200 && signal < 300)
	{
		if (str)
			free(str);
		if (data)
			ft_free_data(data);
		ft_printf("Error: %s\n", error);
		exit (signal);
	}
	else
	{
		if (str)
			free(str);
		if (data)
			ft_free_data(data);
	}
}

void	ft_free_map(char **source)
{
	int	y;

	y = 0;
	while (source[y])
	{
		free(source[y]);
		y++;
	}
	free(source);
}

void	ft_free_data(t_data *data)
{
	if (data->map)
		ft_free_map(data->map);
	if (data->new_map)
		ft_free_map(data->new_map);
	ft_free_image(data);
	free(data);
}

void	ft_free_image(t_data *data)
{
	if (data->img->wall_00)
		mlx_destroy_image(data->mlx, data->img->wall_00);
	if (data->img->coll)
		mlx_destroy_image(data->mlx, data->img->coll);
	if (data->img->exit)
		mlx_destroy_image(data->mlx, data->img->exit);
	if (data->img->player)
		mlx_destroy_image(data->mlx, data->img->player);
	if (data->img->empty)
		mlx_destroy_image(data->mlx, data->img->empty);
	if (data->img->wall_1)
		mlx_destroy_image(data->mlx, data->img->wall_1);
	if (data->img->wall_2)
		mlx_destroy_image(data->mlx, data->img->wall_2);
	if (data->img->player_1)
		mlx_destroy_image(data->mlx, data->img->player_1);
	if (data->img)
		free(data->img);
}
