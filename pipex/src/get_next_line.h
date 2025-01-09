/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:11:31 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:18:51 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000U
# elif BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483646
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 10000U
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# elif MAX_FD < 3 || MAX_FD > 256
#  undef MAX_FD
#  define MAX_FD 256
# endif

char	*get_next_line(int fd);
size_t	better_strlen(const char *str);
void	better_bzero(void *s, size_t n);
char	*dup_and_add(const char *s, unsigned long c);
char	*memdup(const char *s, unsigned long c);

#endif //GET_NEXT_LINE_H
