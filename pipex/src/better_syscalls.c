/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_syscalls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:38:22 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:14:44 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	better_fork(int *forkval)
{
	pid_t	fork_pid;

	fork_pid = fork();
	if (fork_pid < 0)
		perror("fork(2) failure.");
	if (forkval)
	{
		if (is_illegal_memory(forkval))
			perror("better_fork: Send an actual pointer, enjoy the SIGSEGV");
		*forkval = fork_pid;
	}
	return (fork_pid);
}

//NULLABLE 4th param
int	better_open(const char *path, int flags, mode_t mode, int *fd_to_set)
{
	int	fd;

	fd = open(path, flags, mode);
	if (!path)
		return (perror("open(2)"), fd);
	if (mystrlen(path) > FILENAME_MAX)
		perror("open (2): exceeding FILENAME_MAX, might be truncated");
	if (fd < 0)
		perror(path);
	if (fd_to_set)
	{
		if (is_illegal_memory(fd_to_set))
			perror("better_open: Send an actual pointer, enjoy the SIGSEGV");
		*fd_to_set = fd;
	}
	return (fd);
}

int	better_pipe(int pfd[2])
{
	if (pipe(pfd) < 0)
		return (perror("pipe(2)"), -1);
	return (1);
}

int	better_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		return (-1);
	return (1);
}

int	bclose(int *fd)
{
	if (!fd)
		return (perror("bclose: get outta here lil bro, sent NULL"), -1);
	if (is_illegal_memory(fd))
		perror("bclose: Send an actual pointer, enjoy the SIGSEGV");
	if (*fd < 0)
		return (0);
	if (*fd > MAX_FD)
		perror("bclose: that is a crazy fd lil bro,"
			"imma close it eitherways");
	if (close(*fd) < 0)
		perror("close(2)");
	*fd = -1;
	return (1);
}
