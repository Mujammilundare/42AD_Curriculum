/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:38:56 by hbasheer          #+#    #+#             */
/*   Updated: 2024/09/20 15:08:21 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *a, t_list *c)
{
	t_list	*temp;

	temp = a;
	while (c != NULL)
	{
		while (a != NULL)
		{
			if (c->content == a->content)
			{
				a->index = c->index;
				break ;
			}
			a = a->next;
		}
		a = temp;
		c = c->next;
	}
}

void	sorted(t_list *a, t_list *c)
{
	t_list	*temp;
	t_list	*temp1;

	temp = a;
	temp1 = c;
	while (a != NULL)
	{
		if (c->content == a->content)
		{
			a = a->next;
			c = c->next;
		}
		else
			return ;
	}
	ft_free_stack(temp);
	ft_free_stack(temp1);
	exit(0);
}
