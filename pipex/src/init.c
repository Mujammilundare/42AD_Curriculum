/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:21:46 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:35:04 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	clean_pipex_2(t_pipex *pipex)
{
	pipex->ifd = -1;
	pipex->outfilefd = -1;
	pipex->pfd[0] = -1;
	pipex->pfd[1] = -1;
	pipex->piperetval = -1;
	pipex->fork_first = -1;
	pipex->fork_last = -1;
	pipex->status = 0;
	pipex->cmd = NULL;
	pipex->infile_path = NULL;
	pipex->docpipe[0] = -1;
	pipex->docpipe[1] = -1;
	pipex->docbuf = NULL;
	pipex->fork_doc = -1;
	pipex->mp[0] = -1;
	pipex->mp[1] = -1;
	pipex->fork_mid = -1;
	pipex->num_forks = 0;
}

void	clean_pipex_start(const int argc, const char *const *argv,
	t_pipex *pipex)
{
	(void)argv;
	if (!pipex)
		return ;
	clean_pipex_2(pipex);
	pipex->errn = 0;
	if (pipex->bonus_type == PIPE)
		pipex->num_forks = argc - 3;
	else if (pipex->bonus_type == HERE_DOC)
		pipex->num_forks = argc - 4;
	else
		(perror("clean_pipex_start: invalid bonus type"), exit(EXIT_FAILURE));
}

void	init_pipex_fds(const int argc, const char *const *argv, t_pipex *pipex)
{
	((void) argv, (void) argc);
	pipex->piperetval = pipe(pipex->pfd);
	if (pipex->piperetval < 0)
		return (destroy(pipex), perror("pipe"), exit(EXIT_FAILURE));
}
