/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:58:49 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/25 13:58:55 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copymap(char **source, t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	map = NULL;
	map = (char **) malloc((data->height + 1) * sizeof(char *));
	if (!map)
		ft_error_handler("Error", ERROR_MALLOC, NULL, data);
	while (source[i])
	{
		map[i] = ft_strdup(source[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_data_init(t_data *data)
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
	data->wall = NULL;
	data->wall_1 = NULL;
	data->wall_2 = NULL;
	data->coll = NULL;
	data->player = NULL;
	data->player_1 = NULL;
	data->exit = NULL;
	data->empty = NULL;
	data->movements = 1;
	data->bag = 0;
}

void	ft_printmap(char **source)
{
	int	i;

	i = 0;
	ft_printf("\n PRINT MAP \n");
	while (source[i])
	{
		ft_printf("%s\n", source[i]);
		i++;
	}
}
