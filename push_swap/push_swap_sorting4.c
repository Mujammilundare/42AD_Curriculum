/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:17:54 by mundare           #+#    #+#             */
/*   Updated: 2025/02/15 14:48:52 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **st)
{
	int	temp;

	if (*st == NULL || (*st)->next == NULL)
		return ;
	temp = (*st)->data;
	(*st)->data = (*st)->next->data;
	(*st)->next->data = temp;
	temp = (*st)->ind;
	(*st)->ind = (*st)->next->ind;
	(*st)->next->ind = temp;
}

void	ft_sa(t_list **a)
{
	if (*a && ft_lstsize(*a) < 2)
		return ;
	ft_swap(a);
	write (1, "sa\n", 3);
}

void	ft_pa(t_list **a, t_list **b)
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

void	ft_pb(t_list **a, t_list **b)
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

void	ft_rrb(t_list **b)
{
	if (*b && ft_lstsize(*b) < 2)
		return ;
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}
