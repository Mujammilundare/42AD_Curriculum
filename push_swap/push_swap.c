/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:03:50 by mundare           #+#    #+#             */
/*   Updated: 2025/02/08 12:13:51 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit (0);
	if (!validate_arg(av))
		return (write(2, "Error\n", 6));
	intialize_stack(&a, av);
	if (!validate_duplicate(a))
		return (write (2, "Error\n", 6));
	set_index_a(&a);
	if (!ft_is_sorted(a))
		final_sort(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
