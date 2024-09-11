/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:17:11 by mundare           #+#    #+#             */
/*   Updated: 2024/09/11 20:27:19 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE 
    # define FT_GET_NEXT_LINE

# include <unistd.h>
# include <stdio.h>

char *get_next_line(int fd);

#endif