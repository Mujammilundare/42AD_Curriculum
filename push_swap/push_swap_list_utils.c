/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:05:22 by mundare           #+#    #+#             */
/*   Updated: 2025/02/12 20:26:28 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int data, int ind)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->ind = ind;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

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
