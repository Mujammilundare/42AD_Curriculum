/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:03:50 by mundare           #+#    #+#             */
/*   Updated: 2025/02/05 08:03:50 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_h.h"

int main(int ac, char **av)
{
    int tab[10] = NULL;
    char terminator = 32;

    if (ac == 1)
        return(write(1,"Error\n",6));
    else if(ac == 2)
        tab = ft_split(av[2], terminator);
    else
        tab = ft_argument_list(av);
    if (tab == NULL)
        return(write(1,"Error\n",6));
    return (0);
}
