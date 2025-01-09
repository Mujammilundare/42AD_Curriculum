/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:00 by hbasheer          #+#    #+#             */
/*   Updated: 2024/09/20 15:11:36 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_list;

int					check_arg(char **av);
void				check_dup(t_list *s);
long				ft_atol(const char *str);
int					ft_isdigit(int i);
void				ft_error(void);
void				create_stack(t_list **s, char **av);
void				ft_free_stack(t_list *lst);

void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int content, int index);
void				ft_lstadd_back(t_list **lst, t_list *new);

char				**ft_split(char const *s, char c);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				free_split(char **str_arr);

void				set_index(t_list *a, t_list *c);
void				swap(t_list *a, t_list *b);
void				sorted(t_list *a, t_list *c);
void				sort_clone(t_list *lst);

void				ra(t_list **a);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				sa(t_list **a);
void				rra(t_list **a);

void				sort(t_list *a, t_list *b);
void				three_sort(t_list **a);
void				four_sort(t_list **a, t_list **b);
void				five_sort(t_list **a, t_list **b);
void				radix(t_list **a, t_list **b, int size);

#endif