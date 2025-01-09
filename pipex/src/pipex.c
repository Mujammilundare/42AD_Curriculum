/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:54:28 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:47:51 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	usage_and_exit(void)
{
	ssize_t	write_len;

	write_len = write(STDERR_FILENO, USAGE_MAN, mystrlen(USAGE_MAN));
	if (write_len < 0)
		perror("write");
	kill_std();
	exit(EXIT_FAILURE);
}

static int	scan_input(int argc, const char *const *argv)
{
	if (argc != 5 || !argv[1] || !*argv[1] || !argv[2] || !*argv[2]
		|| !argv[3] || !*argv[3] || !argv[4] || !*argv[4]
		|| argv[argc])
		usage_and_exit();
	return (PIPE);
}

int	main(const int argc, const char *const *argv
	, const char *const *envp)
{
	t_pipex	pipex;

	pipex.bonus_type = scan_input(argc, argv);
	clean_pipex_start(argc, argv, &pipex);
	init_pipex_fds(argc, argv, &pipex);
	exec_cmds(argc, argv, envp, &pipex);
	(destroy(&pipex), kill_std());
	return (1);
}
