/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:55:58 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/08 17:33:52 by joneves-         ###   ########.fr       */
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
	if (data->enm->fr)
		ft_free_image(data->enm->fr, data);
	if (data->backg->fr)
		ft_free_image(data->backg->fr, data);
	if (data->plr->fr)
		ft_free_image(data->plr->fr, data);
	if (data->collect->fr)
		ft_free_image(data->collect->fr, data);
	if (!data->mlx)
		free(data);
	free(data->plr);
	free(data->collect);
	free(data->backg);
	free(data->enm);
}

void	ft_free_image(void **fr, t_data *data)
{
	int	i;

	i = 0;
	while (fr[i])
	{
		mlx_destroy_image(data->mlx, fr[i]);
		i++;
	}
	if (fr)
		free(fr);
}
