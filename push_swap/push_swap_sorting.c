/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:54:22 by mundare           #+#    #+#             */
/*   Updated: 2025/02/15 14:39:50 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *st)
{
	while (st != NULL && st->next != NULL)
	{
		if (st->data > st->next->data)
			return (0);
		st = st->next;
	}
	return (1);
}

void	set_index_a(t_list **a)
{
	t_list	*current;
	t_list	*tmp;
	int		index;

	current = *a;
	while (current)
	{
		tmp = *a;
		index = 0;
		while (tmp)
		{
			if (tmp->data < current->data)
				index++;
			tmp = tmp->next;
		}
		current->ind = index;
		current = current->next;
	}
}

void	sort(t_list **a, t_list **b)
{
	ft_divide_and_move(a, b);
	ft_sort_three(a);
	while (*b)
	{
		ft_move_element_to_a(a, b);
		while (ft_get_tail_index(*a) == (*a)->ind - 1)
			ft_rra(a);
	}
}

void	final_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
	{
		ft_sort_two(a);
		return ;
	}
	else if (size == 3)
	{
		ft_sort_three(a);
		return ;
	}
	else
		sort(a, b);
}
