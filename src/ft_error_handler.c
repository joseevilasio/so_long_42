/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:55:58 by joneves-          #+#    #+#             */
/*   Updated: 2024/07/27 22:24:03 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_handler(char *error, int signal, int mode)
{
	if (mode == 0)
	{
		// if (cmds)
		// 	ft_free_args(cmds);
		perror(error);
		exit (signal);
	}
	else
	{
		ft_printf("Error: %s\n", error);
		exit (signal);
	}
}