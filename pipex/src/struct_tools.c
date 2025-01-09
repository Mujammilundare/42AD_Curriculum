/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:13:54 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:16:24 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	destroy(t_pipex *pipex)
{
	if (!pipex)
		return (perror("destroy fds: NULL pointer"), -1);
	if (pipex->ifd > -1)
		(close(pipex->ifd), pipex->ifd = -1);
	if (pipex->outfilefd > -1)
		(close(pipex->outfilefd), pipex->outfilefd = -1);
	if (pipex->pfd[0] > -1)
		(close(pipex->pfd[0]), pipex->pfd[0] = -1);
	if (pipex->pfd[1] > -1)
		(close(pipex->pfd[1]), pipex->pfd[1] = -1);
	if (pipex->docpipe[0] > -1)
		(close(pipex->docpipe[0]), pipex->docpipe[0] = -1);
	if (pipex->docpipe[1] > -1)
		(close(pipex->docpipe[1]), pipex->docpipe[1] = -1);
	if (pipex->docbuf)
		(free(pipex->docbuf), pipex->docbuf = NULL);
	return (0);
}

int	better_free(void **p)
{
	if (!p)
		return (perror(""), -1);
	if (!*p)
		return (perror("better_free: Ensure your memory logic is good"), 0);
	free(*p);
	*p = NULL;
	return (1);
}

int	kill_std(void)
{
	if (close(STDIN_FILENO) < 0)
		perror("close(2): close stdin");
	if (close(STDOUT_FILENO) < 0)
		perror("close(2): close stdout");
	if (close(STDERR_FILENO) < 0)
		perror("close(2): close stderr");
	return (1);
}
