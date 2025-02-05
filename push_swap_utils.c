/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:04:55 by mundare           #+#    #+#             */
/*   Updated: 2025/02/05 08:04:55 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	*copystr(char const *s, char c, char *str)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, i);
	return (str);
}

void	*allocate(char **str_arr, char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = count_words(s, c);
	str_arr = ((malloc(sizeof(char *) * (words + 1))));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		str_arr[i] = copystr(s, c, str_arr[i]);
		if (!str_arr[i])
		{
			free_array(str_arr);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;

	str_arr = NULL;
	if (s == NULL)
		return (NULL);
	str_arr = allocate(str_arr, s, c);
	return (str_arr);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

char **ft_argument_list(int ac, char **av)
{
    int i;
	int j;
	char **tab;
	
	tab = malloc(sizeof(char *) * ac);
    i = 1;
	j = 0;
	while (av[i])
	{
		tab[j] = copystr(s, c, tab[j]);



		// printf("%s ",av[i]);
		// j = 0;
		// while (av[j])
		// 	tab[i] = av[++j];
		// i++;
	}	
	tab[i] = 0;
	return (ft_split(tab, 32));
}