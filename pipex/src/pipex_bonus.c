/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:06:18 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:48:03 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	usage_and_exit(void)
{
	if (write(STDERR_FILENO, USAGE, mystrlen(USAGE)) < 0)
		perror("write");
	if (write(STDERR_FILENO, USAGE2, mystrlen(USAGE2)) < 0)
		perror("write");
	if (write(STDERR_FILENO, USAGE3, mystrlen(USAGE3)) < 0)
		perror("write");
	kill_std();
	exit(EXIT_FAILURE);
}

static int	scan_input(int argc, const char *const *argv)
{
	if (argc < 5)
		usage_and_exit();
	if (!argv || !*argv || !**argv || !argv[1] || !*argv[1])
		usage_and_exit();
	if (mystrncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc != 6 || !argv[1] || !argv[2]
			|| !argv[3] || !argv[4]
			|| !argv[5] || argv[argc])
			usage_and_exit();
		return (HERE_DOC);
	}
	return (PIPE);
}

int	main(const int argc, const char *const *argv, const char *const *envp)
{
	t_pipex	pipex;

	pipex.bonus_type = scan_input(argc, argv);
	clean_pipex_start(argc, argv, &pipex);
	init_pipex_fds(argc, argv, &pipex);
	if (pipex.bonus_type == HERE_DOC)
		exec_heredoc(argc, argv, envp, &pipex);
	else if (pipex.bonus_type == PIPE)
		exec_cmds(argc, argv, envp, &pipex);
	else
		perror("main: invalid bonus type");
	(destroy(&pipex), kill_std());
	return (1);
}
