/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:55:58 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/31 23:46:15 by joneves-         ###   ########.fr       */
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
		ft_printf("Error\n %s\n", error);
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
	if (data->enemy->frames)
		ft_free_image(data->enemy->frames, data);
	if (data->background->frames)
		ft_free_image(data->background->frames, data);
	if (data->player->frames)
		ft_free_image(data->player->frames, data);
	if (data->collectibles->frames)
		ft_free_image(data->collectibles->frames, data);
	if (!data->mlx)
		free(data);
	free(data->player);
	free(data->collectibles);
	free(data->background);
	free(data->enemy);
}

void	ft_free_image(void **frames, t_data *data)
{
	int	i;

	i = 0;
	while (frames[i])
	{
		mlx_destroy_image(data->mlx, frames[i]);
		i++;
	}
	if (frames)
		free(frames);
	
}
