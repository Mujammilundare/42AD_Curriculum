/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:17:11 by mundare           #+#    #+#             */
/*   Updated: 2025/01/08 13:14:32 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);

#endif
