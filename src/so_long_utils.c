/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:36:31 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/11 13:16:23 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *pathname)
{
	int		fd;
	char	*filename;

	filename = ft_strnstr(pathname, ".ber", ft_strlen(pathname));
	if (filename == NULL || ft_strlen(filename) != 4)
		ft_error_handler("Invalid file type.", ERROR_TYPE, 1, NULL);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		ft_error_handler("Error", ERROR_OPEN, 0, NULL);
	return (fd);
}

char	*ft_strremove(char *str, char *target)
{
	char	*new_str;

	new_str = ft_strtrim(str, target);
	if (!new_str)
		return (str);
	free(str);
	return (new_str);
}

void	ft_init(t_init *initial)
{
	initial->size = (int *) malloc(2 * sizeof(int));
	if (!initial->size)
		ft_error_handler("Error", ERROR_MALLOC, 0, NULL);
	initial->pos_p = (int *) malloc(2 * sizeof(int));
	if (!initial->size)
		ft_error_handler("Error", ERROR_MALLOC, 0, NULL);
	initial->p = 0;
	initial->e = 0;
	initial->c = 0;
	initial->ff_e = 0;
	initial->ff_c = 0;
	initial->size[0] = 1;
	initial->size[1] = 0;
}

void	ft_printmap(int **map, t_init map_init)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_init.size[0])
	{
		x = 0;
		while (x < map_init.size[1])
			ft_printf("%c", map[y][x++]);
		ft_printf("\n");
		y++;
	}
}
