/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mem_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:28:21 by mundare           #+#    #+#             */
/*   Updated: 2025/02/13 19:37:26 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list **a)
{
	t_list	*tmp;

	while (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

void	ft_free_stack2(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (lst != NULL)
	{
		lst = lst->next;
		free(temp);
		temp = lst;
	}
}
