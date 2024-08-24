/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:55:58 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/24 19:32:39 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	data = NULL;
}

void	ft_free_image(t_data *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->coll)
		mlx_destroy_image(data->mlx, data->coll);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->empty)
		mlx_destroy_image(data->mlx, data->empty);
	if (data->wall_1)
		mlx_destroy_image(data->mlx, data->wall_1);
	if (data->wall_2)
		mlx_destroy_image(data->mlx, data->wall_2);
}
