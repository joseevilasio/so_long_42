/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:58:49 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/18 15:48:47 by joneves-         ###   ########.fr       */
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
