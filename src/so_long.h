/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:28:56 by joneves-          #+#    #+#             */
/*   Updated: 2024/07/29 20:57:01 by joneves-         ###   ########.fr       */
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
# define ERROR_INVALID_TYPE 2
# define ERROR_OPEN 3
# define ERROR_READ 4
# define ERROR_INVALID_MAP 3

int		ft_ismapvalid(char *map);
void	ft_error_handler(char *error, int signal, int mode, char *str);

// Utils
int		ft_open(char *pathname);
size_t	ft_countlines(char *pathname);
char	*ft_strremove(char *str, char *target);

#endif //SO_LONG_H