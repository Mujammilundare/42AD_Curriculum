/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:14 by hbasheer          #+#    #+#             */
/*   Updated: 2024/09/17 16:39:15 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
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
