/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:52:21 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 15:54:06 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

ssize_t	better_write(const int fd, const void *const buf
	, const size_t bytecount)
{
	ssize_t	write_count;

	if (fd < 0)
		perror("better_write: negative fd lil bro?");
	if (fd > MAX_FD)
		perror("better_write: that is a crazy fd lil bro,"
			"imma write into it eitherways");
	write_count = write(fd, buf, bytecount);
	if (write_count < 0)
		perror("write(2)");
	return (write_count);
}

int	is_open_fd(int fd)
{
	return (write(fd, NULL, 0) != -1 || read(fd, NULL, 0) != -1);
}

int	is_writable_fd(int fd)
{
	return (write(fd, NULL, 0) != -1);
}

int	is_readable_fd(int fd)
{
	return (read(fd, NULL, 0) != -1);
}

int	is_illegal_memory(const void *p)
{
	if (!p)
		return (perror("is_illegal_memory: NULL pointer"), 1);
	if (p <= (const void *)0xFFFFF)
		return (perror("illegal memory range"), 1);
	return (0);
}
