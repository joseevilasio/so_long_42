/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/03 23:36:22 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// int		**map;

	// map = NULL;
	if (argc == 2)
	{
		ft_loadmap(argv[1]);
		ft_printf("> %s < executando... \n\n", argv[1]);
	}
	else
		ft_error_handler(strerror(EINVAL), ERROR_ARGUMENTS, 1, NULL);
	return (0);
}
