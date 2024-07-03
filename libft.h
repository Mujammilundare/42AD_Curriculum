/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:00:24 by mundare           #+#    #+#             */
/*   Updated: 2024/07/02 18:45:16 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
int		ft_tolower(int i);
int		ft_toupper(int i);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int i);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, char *s2, size_t n);
int		ft_atoi(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);

#endif