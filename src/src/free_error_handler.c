/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:55:58 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/18 22:34:20 by joneves-         ###   ########.fr       */
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
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_coll)
		mlx_destroy_image(data->mlx, data->img_coll);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_empty)
		mlx_destroy_image(data->mlx, data->img_empty);
	data = NULL;
}
