/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:03:29 by mundare           #+#    #+#             */
/*   Updated: 2025/02/12 20:34:14 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	if (first->data > second->data)
		sa(stack);
}

void	handle_sorting_cases(t_list **a, t_list *f,	t_list *s, t_list *t)
{
	if (f->data > s->data && f->data > t->data)
	{
		ra(a);
		if (s->data > t->data)
			sa(a);
		return ;
	}
	if (s->data > f->data && f->data > t->data)
	{
		rra(a);
		return ;
	}
	if (s->data > f->data && s->data > t->data)
	{
		sa(a);
		ra(a);
		return ;
	}
	if (t->data > f->data && t->data > s->data)
	{
		if (f->data > s->data)
			sa(a);
		return ;
	}
}

void	ft_sort_three(t_list **st)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;

	if (!(st) || !(*st)->next || !(*st)->next->next)
		return ;
	f = *st;
	s = f->next;
	t = s->next;
	if (ft_is_sorted(*st))
		return ;
	handle_sorting_cases(st, f, s, t);
}

int	ft_find_index(t_list *stack, int target)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->ind == target)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	ft_get_tail_index(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->ind);
}

void	ft_move_top_elements_to_a(t_list **a, t_list **b, int last_idx_a)
{
	while ((*b)->ind != (*a)->ind - 1)
	{
		if ((*b)->ind > last_idx_a)
		{
			last_idx_a = (*b)->ind;
			pa(a, b);
			ra(a);
		}
		else
			rb(b);
	}
	pa(a, b);
}

void	ft_move_bottom_elements_to_a(t_list **a, t_list **b)
{
	while ((*b)->ind != (*a)->ind - 1)
		rrb(b);
	pa(a, b);
}

void	ft_move_element_to_a(t_list **a, t_list **b)
{
	int	last_idx_a;

	last_idx_a = 0;
	if (ft_get_tail_index(*a) < (*a)->ind)
		last_idx_a = ft_get_tail_index(*a);
	if (ft_find_index(*b, (*a)->ind - 1) < ft_lstsize(*b) / 2)
		ft_move_top_elements_to_a(a, b, last_idx_a);
	else
		ft_move_bottom_elements_to_a(a, b);
}

void	ft_partition_and_move(t_list **a, t_list **b, int pv1, int size)
{
	while (ft_lstsize(*b) < pv1 + size)
	{
		if ((*a)->ind < pv1 + size)
			pb(a, b);
		else
			ra(a);
		if (*b != NULL && (*b)->ind <= pv1 + size / 2 && (*b)->ind >= pv1)
			rb(b);
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


void	handle_large_sort(t_list **a, t_list **b)
{
	ft_divide_and_move(a, b);
	ft_sort_three(a);
	while (*b)
	{
		ft_move_element_to_a(a, b);
		while (ft_get_tail_index(*a) == (*a)->ind - 1)
			rra(a);
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
		handle_large_sort(a, b);
}
