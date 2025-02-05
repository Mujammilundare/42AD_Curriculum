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

#include "push_swap.h"

int main(int ac, char **av)
{
    char **tab = NULL;

    if (ac == 1)
        exit(0);
    if(!validate_arg(av))
		return(write(1,"Error\n",6));


    return (0);
}