/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:55:58 by joneves-          #+#    #+#             */
/*   Updated: 2024/07/29 20:19:22 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_handler(char *error, int signal, int mode, char *str)
{
	if (mode == 0)
	{
		if (str)
			free(str);
		perror(error);
		exit (signal);
	}
	else
	{
		if (str)
			free(str);
		ft_printf("Error: %s\n", error);
		exit (signal);
	}
}
