/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:31 by hbasheer          #+#    #+#             */
/*   Updated: 2024/09/20 14:56:42 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list *lst)
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

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
