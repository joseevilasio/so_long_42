/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:28:56 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/08 09:02:12 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>

# define SUCCESS 0
# define ERROR_ARGUMENTS 1
# define ERROR_TYPE 2
# define ERROR_OPEN 3
# define ERROR_READ 4
# define ERROR_MAP 5
# define ERROR_MALLOC 6

void	ft_error_handler(char *error, int signal, int mode, char *str);
int	    ft_loadmap(char *pathname);
void	ft_floodfill(int **map, size_t *size, int x, int y);

// Utils
int		ft_open(char *pathname);
char	*ft_strremove(char *str, char *target);

#endif //SO_LONG_H