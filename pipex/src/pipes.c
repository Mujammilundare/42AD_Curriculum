/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:18:02 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:18:15 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_cmd_first(const int argc, const char *const *argv,
	const char *const *envp, t_pipex *p)
{
	(void)argc;
	if (better_pipe(p->pfd) < 0)
		(destroy(p), kill_std(), exit(EXIT_FAILURE));
	if (better_fork(&p->fork_first) < 0)
		(destroy(p), kill_std(), exit(EXIT_FAILURE));
	if (p->fork_first == 0)
	{
		p->ifd = open(argv[1], O_RDONLY);
		if (p->ifd < 0)
			(perror(argv[1]), destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (bclose(&p->pfd[0]) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (better_dup2(p->ifd, STDIN_FILENO) < 0 || bclose(&p->ifd) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (better_dup2(p->pfd[1], STDOUT_FILENO) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (bclose(&p->pfd[1]) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		(destroy(p), pseudo_execlp(argv[2], envp, p));
	}
	if (bclose(&p->pfd[1]) < 0)
		(destroy(p), kill_std(), exit(EXIT_FAILURE));
	if (better_dup2(p->pfd[0], STDIN_FILENO) < 0 || bclose(&p->pfd[0]) < 0)
		(destroy(p), kill_std(), exit(EXIT_FAILURE));
}

void	exec_cmd_last(const int argc, const char *const *argv,
	const char *const *envp, t_pipex *p)
{
	if (better_fork(&p->fork_last) < 0)
		(destroy(p), kill_std(), exit(EXIT_FAILURE));
	if (p->fork_last == 0)
	{
		if (better_open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC,
				0644, &p->outfilefd) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (better_dup2(p->outfilefd, STDOUT_FILENO) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (bclose(&p->outfilefd) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		(destroy(p), pseudo_execlp(argv[argc - 2], envp, p));
		(destroy(p), kill_std(), exit(127));
	}
	kill_std();
}

void	exec_mid_cmds(const int argc, const char *const *argv,
		const char *const *envp, t_pipex *p)
{
	int	i;

	i = -1;
	while (++i < argc - 2)
	{
		if (better_pipe(p->mp) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (better_fork(&p->fork_mid) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (p->fork_mid == 0)
		{
			if (bclose(&p->mp[0]) < 0)
				(destroy(p), kill_std(), exit(EXIT_FAILURE));
			if (better_dup2(p->mp[1], STDOUT_FILENO) < 0)
				(destroy(p), kill_std(), exit(EXIT_FAILURE));
			if (bclose(&p->mp[1]) < 0)
				(destroy(p), kill_std(), exit(EXIT_FAILURE));
			(destroy(p), pseudo_execlp(argv[i], envp, p));
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		}
		if (bclose(&p->mp[1]) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
		if (better_dup2(p->mp[0], STDIN_FILENO) < 0 || bclose(&p->mp[0]) < 0)
			(destroy(p), kill_std(), exit(EXIT_FAILURE));
	}
}

void	exec_cmds(const int argc, const char *const *argv
	, const char *const *envp, t_pipex *p)
{
	int	exit_status;

	(bclose(&p->pfd[0]), bclose(&p->pfd[1]));
	exec_cmd_first(argc, argv, envp, p);
	exec_mid_cmds(argc - 3, argv + 3, envp, p);
	exec_cmd_last(argc, argv, envp, p);
	destroy(p);
	while (--p->num_forks)
		wait(NULL);
	waitpid(p->fork_last, &p->status, 0);
	exit_status = p->status;
	if (WIFSIGNALED(p->status))
		exit(WTERMSIG(exit_status) + 128);
	exit(WEXITSTATUS(p->status));
}
