/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:38:41 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:39:21 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	frall(const char **arrays)
{
	unsigned int	i;

	i = -1;
	while (arrays[++i])
		(free((void *) arrays[i]), arrays[i] = NULL);
	(free(arrays), arrays = NULL);
}
