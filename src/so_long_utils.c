/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:36:31 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/04 21:41:52 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *pathname)
{
	int	fd;
	
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
