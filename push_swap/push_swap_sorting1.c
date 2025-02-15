/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:31:47 by mundare           #+#    #+#             */
/*   Updated: 2025/02/15 14:42:30 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_top_elements_to_a(t_list **a, t_list **b, int last_idx_a)
{
	while ((*b)->ind != (*a)->ind - 1)
	{
		if ((*b)->ind > last_idx_a)
		{
			last_idx_a = (*b)->ind;
			ft_pa(a, b);
			ft_ra(a);
		}
		else
			ft_rb(b);
	}
	ft_pa(a, b);
}

void	ft_move_bottom_elements_to_a(t_list **a, t_list **b)
{
	while ((*b)->ind != (*a)->ind - 1)
		ft_rrb(b);
	ft_pa(a, b);
}

void	ft_move_element_to_a(t_list **a, t_list **b)
{
	int	last_idx_a;

	last_idx_a = 0;
	if (ft_get_tail_index(*a) < (*a)->ind)
		last_idx_a = ft_get_tail_index(*a);
	if (ft_find_index(*b, (*a)->ind - 1)
		< ft_lstsize(*b) / 2)
		ft_move_top_elements_to_a(a, b, last_idx_a);
	else
		ft_move_bottom_elements_to_a(a, b);
}

void	ft_partition_and_move(t_list **a, t_list **b, int pv1, int size)
{
	while (ft_lstsize(*b) < pv1 + size)
	{
		if ((*a)->ind < pv1 + size)
			ft_pb(a, b);
		else
			ft_ra(a);
		if (*b != NULL && (*b)->ind
			<= pv1 + size / 2 && (*b)->ind >= pv1)
			ft_rb(b);
	}
}

void	ft_divide_and_move(t_list **a, t_list **b)
{
	int	pv1;
	int	size;

	pv1 = 0;
	while (ft_lstsize(*a) > 3)
	{
		size = ft_lstsize(*a) / 3;
		if (size < 10)
			size = ft_lstsize(*a) - 3;
		ft_partition_and_move(a, b, pv1, size);
		pv1 += size;
	}
}
