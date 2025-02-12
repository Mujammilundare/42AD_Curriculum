/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:03:29 by mundare           #+#    #+#             */
/*   Updated: 2025/02/12 20:42:03 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **st)
{
	t_list	*tmp;

	if (*st == NULL || (*st)->next == NULL)
		return ;
	tmp = *st;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *st;
	*st = (*st)->next;
	tmp->next->next = NULL;
}

void	ft_reverse_rotate(t_list **st)
{
	t_list	*tmp;
	t_list	*last;

	if (*st == NULL || (*st)->next == NULL)
		return ;
	tmp = *st;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	last->next = *st;
	*st = last;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	sa(t_list **a)
{
	t_list	*temp;

	if (ft_lstsize(*a) < 2 || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	write(1, "sa\n", 3);
}

void	ra(t_list **a)
{
	if (*a && ft_lstsize(*a) < 2)
		return ;
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rra(t_list **a)
{
	if (*a && ft_lstsize(*a) < 2)
		return ;
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rb(t_list **b)
{
	if (*b && ft_lstsize(*b) < 2)
		return ;
	ft_rotate(b);
	write(1, "rb\n", 4);
}

void	rrb(t_list **b)
{
	if (*b && ft_lstsize(*b) < 2)
		return ;
	ft_reverse_rotate(b);
	write(1, "rrb\n", 5);
}
