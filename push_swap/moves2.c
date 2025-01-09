/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:12 by hbasheer          #+#    #+#             */
/*   Updated: 2024/09/17 16:39:13 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*temp;
	t_list	*first;

	if (ft_lstsize(*a) == 1 || !*a)
		return ;
	temp = ft_lstlast(*a);
	first = *a;
	temp->next = first;
	*a = first->next;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	temp = *a;
	last = ft_lstlast(*a);
	if (!last)
		return ;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}
