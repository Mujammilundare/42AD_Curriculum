/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:45:44 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:14:44 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_heredoc_buf(const char *const delimiter)
{
	char	*line;
	char	*temp;
	char	*final;

	final = (char *)mystrdup("");
	if (!delimiter)
		return (NULL);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (free(final), NULL);
		if (!delimiter[0] || !mystrncmp(line, delimiter
				, mystrlen(delimiter) - 1))
			if (line[mystrlen(delimiter)] == '\n')
				return (free(line), final);
		temp = final;
		final = mystrjoin(final, line);
		(free(temp), temp = NULL);
		(free(line), line = NULL);
		if (!final)
			return (NULL);
	}
}

int	heredoc_buf(const char *const delimiter, int fd)
{
	char	*line;

	if (!delimiter)
		return (perror("heredoc_buf: NULL delimiter"), -1);
	if (fd < 0)
		return (perror("heredoc_buf: negative fd lil bro?"), -1);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (-1);
		if (!delimiter[0] || !mystrncmp(line, delimiter
				, mystrlen(delimiter) - 1))
			if (line[mystrlen(delimiter)] == '\n')
				return (better_free((void **)&line), 1);
		(better_write(fd, line, mystrlen(line)), better_free((void **)&line));
	}
}

void	exec_doc_2(const int argc, const char *const *argv,
	const char *const *envp, t_pipex *pipex)
{
	if (bclose(&pipex->pfd[1]) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (better_open(argv[argc - 1], O_APPEND | O_CREAT | O_WRONLY
			, 0644, &pipex->outfilefd) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (better_dup2(pipex->outfilefd, STDOUT_FILENO) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (bclose(&pipex->outfilefd) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (better_dup2(pipex->pfd[0], STDIN_FILENO) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (bclose(&pipex->pfd[0]) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	destroy(pipex);
	pseudo_execlp(argv[argc - 2], envp, pipex);
	(destroy(pipex), kill_std(), exit(127));
}

void	exec_doc_1(const int argc, const char *const *argv
	, const char *const *envp, t_pipex *pipex)
{
	(void)argc;
	if (better_dup2(pipex->docpipe[0], STDIN_FILENO) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (bclose(&pipex->docpipe[0]) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (bclose(&pipex->pfd[0]) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (better_dup2(pipex->pfd[1], STDOUT_FILENO) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	if (bclose(&pipex->pfd[1]) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	destroy(pipex);
	pseudo_execlp(argv[3], envp, pipex);
	(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
}

void	exec_heredoc(const int argc, const char *const *argv
	, const char *const *envp, t_pipex *pipex)
{
	int	code;

	if (better_pipe(pipex->docpipe) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	heredoc_buf(argv[2], pipex->docpipe[1]);
	if (bclose(&pipex->docpipe[1]) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	better_fork(&pipex->fork_doc);
	if (!pipex->fork_doc)
		exec_doc_1(argc, argv, envp, pipex);
	if (bclose(&pipex->docpipe[0]) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	better_fork(&pipex->fork_last);
	if (!pipex->fork_last)
		exec_doc_2(argc, argv, envp, pipex);
	if (bclose(&pipex->pfd[0]) < 0 || bclose(&pipex->pfd[1]) < 0)
		(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	waitpid(pipex->fork_doc, NULL, 0);
	waitpid(pipex->fork_last, &pipex->status, 0);
	code = WEXITSTATUS(pipex->status);
	(destroy(pipex), kill_std());
	if (WIFSIGNALED(pipex->status))
		exit(WTERMSIG(code) + 128);
	exit(WEXITSTATUS(pipex->status));
}
