/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:04:32 by mundare           #+#    #+#             */
/*   Updated: 2025/02/05 08:04:32 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_list
{
	int				ind;
	int				data;
	struct s_list	*next;
}					t_list;

void	ft_error(void);
int		validate_arg(char **av);
void	intialize_stack(t_list **s, char **av);
void	ft_free_stack(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content, int index);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t elm_count, size_t elm_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	free_array(char **str_arr);
void	free_split(char **str_arr);
int		validate_duplicate(t_list *s);
void	sort_clone(t_list *lst);
void	sorted(t_list *a, t_list *c);
void	set_index(t_list *a, t_list *c);
void	sort(t_list *a, t_list *b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	sa(t_list **a);
void	ra(t_list **a);
void	ra(t_list **a);
void	rra(t_list **a);
void	radix(t_list **a, t_list **b, int size);
void	push(t_list **a, t_list **b);
void	ft_free_stack(t_list *lst);
void	ft_error(void);
