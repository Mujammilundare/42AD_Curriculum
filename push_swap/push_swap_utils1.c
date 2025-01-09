/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:38:44 by hbasheer          #+#    #+#             */
/*   Updated: 2024/09/20 15:04:59 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_list **s, char *arg)
{
	int		j;
	long	n;
	char	**temp;

	j = 0;
	temp = ft_split(arg, ' ');
	if (!temp || !(temp[0]))
		return (free_split(temp), 0);
	while (temp[j])
	{
		if ((temp[j][0] == '-' || temp[j][0] == '+') && temp[j][1] == '\0')
			return (free_split(temp), 0);
		n = ft_atol(temp[j]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_split(temp), 0);
		ft_lstadd_back(s, ft_lstnew(n, 0));
		j++;
	}
	free_split(temp);
	return (1);
}

void	create_stack(t_list **s, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!add_node(s, av[i]))
		{
			ft_free_stack(*s);
			ft_error();
		}
		i++;
	}
}

void	swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void	sort_clone(t_list *lst)
{
	int		i;
	t_list	*temp;

	if (!lst)
		exit(1);
	temp = lst;
	while (lst->next != NULL)
	{
		if (lst->content > lst->next->content)
		{
			swap(lst, lst->next);
			lst = temp;
		}
		else
			lst = lst->next;
	}
	lst = temp;
	i = 0;
	while (lst != NULL)
	{
		lst->index = i;
		i++;
		lst = lst->next;
	}
}
