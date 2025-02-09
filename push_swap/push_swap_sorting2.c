/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:00:55 by mundare           #+#    #+#             */
/*   Updated: 2025/02/09 13:01:27 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_list *a, int n)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		if (a->ind == n)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

void	three_sort(t_list **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->ind;
	s = (*a)->next->ind;
	t = (*a)->next->next->ind;
	if (f == 0 && s == 2 && t == 1)
	{
		rra(a);
		sa(a);
	}
	else if (f == 1 && s == 0 && t == 2)
		sa(a);
	else if (f == 1 && s == 2 && t == 0)
		rra(a);
	else if (f == 2 && s == 1 && t == 0)
	{
		ra(a);
		sa(a);
	}
	else if (f == 2 && s == 0 && t == 1)
		ra(a);
}

void	four_sort(t_list **a, t_list **b)
{
	int	pos;

	pos = find_pos(*a, 3);
	if (pos <= 4 / 2)
	{
		while ((*a)->ind != 3)
			ra(a);
	}
	else
	{
		while ((*a)->ind != 3)
			rra(a);
	}
	pb(a, b);
	three_sort(a);
	pa(a, b);
	ra(a);
}

void	five_sort(t_list **a, t_list **b)
{
	int	pos;

	pos = find_pos(*a, 4);
	if (pos <= 5 / 2)
	{
		while ((*a)->ind != 4)
			ra(a);
	}
	else
	{
		while ((*a)->ind != 4)
			rra(a);
	}
	pb(a, b);
	four_sort(a, b);
	pa(a, b);
	ra(a);
}

void	sort(t_list *a, t_list *b)
{
	int	size;

	size = ft_lstsize(a);
	if (size == 2)
		sa(&a);
	else if (size == 3)
		three_sort(&a);
	else if (size == 4)
		four_sort(&a, &b);
	else if (size == 5)
		five_sort(&a, &b);
	else
	{
		radix(&a, &b, size);
	}
	ft_free_stack(a);
}
