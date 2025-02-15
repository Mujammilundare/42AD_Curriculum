/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:03:29 by mundare           #+#    #+#             */
/*   Updated: 2025/02/15 14:46:14 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_list *st, int target)
{
	int	i;

	i = 0;
	while (st != NULL)
	{
		if (st->ind == target)
			return (i);
		i++;
		st = st->next;
	}
	return (-1);
}

int	ft_get_tail_index(t_list *st)
{
	if (!st)
		return (0);
	while (st->next)
	{
		st = st->next;
	}
	return (st->ind);
}

void	ft_sort_two(t_list **st)
{
	t_list	*f;
	t_list	*s;

	f = *st;
	s = f->next;
	if (f->data > s->data)
		ft_sa(st);
}

void	handle_sorting_cases(t_list **st, t_list *f, t_list *s, t_list *t)
{
	if (f->data > s->data && f->data > t->data)
	{
		ft_ra(st);
		if (s->data > t->data)
			ft_sa(st);
		return ;
	}
	if (s->data > f->data && f->data > t->data)
	{
		ft_rra(st);
		return ;
	}
	if (s->data > f->data && s->data > t->data)
	{
		ft_sa(st);
		ft_ra(st);
		return ;
	}
	if (t->data > f->data && t->data > s->data)
	{
		if (f->data > s->data)
			ft_sa(st);
		return ;
	}
}

void	ft_sort_three(t_list **st)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;

	if (!(*st) || !(*st)->next || !(*st)->next->next)
		return ;
	f = *st;
	s = f->next;
	t = s->next;
	if (ft_is_sorted(*st))
		return ;
	handle_sorting_cases(st, f, s, t);
}
