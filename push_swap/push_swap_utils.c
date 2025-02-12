/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:50:56 by mundare           #+#    #+#             */
/*   Updated: 2025/02/12 20:28:11 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int i)
{
	while (i >= '0' && i <= '9')
		return (1);
	return (0);
}

int	validate_arg(char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j])
						|| (av[i][j] == '-' && (av[i][j - 1] == ' ' || j == 0))
						|| (av[i][j] == '+' && (av[i][j - 1] == ' ' || j == 0))
						|| av[i][j] == ' ')
				flag = 1;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (flag);
}

int	validate_duplicate(t_list *s)
{
	t_list	*tmp;
	t_list	*compare;

	tmp = s;
	while (s != NULL)
	{
		compare = s->next;
		while (compare != NULL)
		{
			if (s->data == compare->data)
			{
				ft_free_stack2(tmp);
				return (0);
			}
			compare = compare->next;
		}
		s = s->next;
	}
	return (1);
}

int	add_node(t_list **s, char *arg)
{
	int		i;
	long	num;
	char	**str;

	i = 0;
	str = ft_split(arg, ' ');
	if (!str || !(str[0]))
		return (free_split(str), 0);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_split(str), 0);
		ft_lstadd_back(s, ft_lstnew(num, 0));
		i++;
	}
	free_split(str);
	return (1);
}

void	intialize_stack(t_list **a, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!add_node(a, av[i]))
		{
			ft_free_stack(a);
			ft_error();
		}
		i++;
	}
}
