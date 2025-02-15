/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:03:29 by mundare           #+#    #+#             */
/*   Updated: 2025/02/15 14:47:24 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **st)
{
	t_list	*temp;

	if (*st == NULL || (*st)->next == NULL)
		return ;
	temp = *st;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *st;
	*st = (*st)->next;
	temp->next->next = NULL;
}

void	ft_reverse_rotate(t_list **st)
{
	t_list	*temp;
	t_list	*last;

	if (*st == NULL || (*st)->next == NULL)
		return ;
	temp = *st;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	last = temp->next;
	temp->next = NULL;
	last->next = *st;
	*st = last;
}

void	ft_rb(t_list **b)
{
	if (*b && ft_lstsize(*b) < 2)
		return ;
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_ra(t_list **a)
{
	if (*a && ft_lstsize(*a) < 2)
		return ;
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rra(t_list **a)
{
	if (*a && ft_lstsize(*a) < 2)
		return ;
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}
