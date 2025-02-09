/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:54:22 by mundare           #+#    #+#             */
/*   Updated: 2025/02/09 15:10:24 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *a, t_list *b)
{
	int	tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

void	sort_clone(t_list *lst)
{
	int		i;
	t_list	*tmp;

	if (!lst)
		exit(1);
	tmp = lst;
	while (lst->next != NULL)
	{
		if (lst->data > lst->next->data)
		{
			swap(lst, lst->next);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	i = 0;
	while (lst != NULL)
	{
		lst->ind = i;
		i++;
		lst = lst->next;
	}
}

void	sorted(t_list *a, t_list *c)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = a;
	tmp1 = c;
	while (a != NULL)
	{
		if (c->data == a->data)
		{
			a = a->next;
			c = c->next;
		}
		else
			return ;
	}
	ft_free_stack(tmp);
	ft_free_stack(tmp1);
	exit(0);
}

void	set_index(t_list *a, t_list *c)
{
	t_list	*tmp;

	tmp = a;
	while (c != NULL)
	{
		while (a != NULL)
		{
			if (c->data == a->data)
			{
				a->ind = c->ind;
				break ;
			}
			a = a->next;
		}
		a = tmp;
		c = c->next;
	}
}

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a == NULL)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	if ((*b) == NULL)
	{
		temp->next = NULL;
		(*b) = temp;
	}
	else
	{
		temp->next = *b;
		*b = temp;
	}
}
