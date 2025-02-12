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
int		validate_duplicate(t_list *s);
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
int		ft_is_sorted(t_list *a);
void	set_index_a(t_list **a);
void	final_sort(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	sa(t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	ft_free_stack(t_list **a);
void	ft_free_stack2(t_list *a); 
