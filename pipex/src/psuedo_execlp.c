/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psuedo_execlp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:30:51 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:29:40 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*
 * Execve favors the bold, fuzz it with sudo privileges.
 */

//STACK NON-FREEABLE RETURN
const char	*path_finder(const char *const *envp)
{
	unsigned int	i;

	i = -1;
	if (!envp)
		return (perror("path_finder: NULL pointer"), NULL);
	while (envp[++i])
		if (mystrncmp(envp[i], X_ENV, mystrlen(X_ENV) - 1) == 0)
			return (envp[i] + mystrlen(X_ENV));
	return (NULL);
}

const char	*dupcmd(const char *cmd)
{
	const char		*parsed_cmd;
	unsigned int	i;

	i = 0;
	if (!cmd)
		return (perror("dupcmd: NULL pointer"), NULL);
	while (cmd[i] && (cmd[i] == '.' || cmd[i] == '/'))
		i++;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	parsed_cmd = mystrndup(cmd, i);
	return (parsed_cmd);
}

const char	*getcmd(const char *cmd, const char *const *envp, int i)
{
	const char		**splitted_path;
	const char		*full_cmd;
	const char		*dupped_cmd;

	if (!cmd || !envp)
		return (perror("getcmd: NULL pointer"), NULL);
	dupped_cmd = dupcmd(cmd);
	if (!dupped_cmd)
		return (perror("getcmd: dupcmd"), NULL);
	if (is_absolute_path(dupped_cmd))
		return (dupped_cmd);
	splitted_path = mysplit(path_finder(envp), ':');
	if (!splitted_path)
		return (perror("getcmd"), free((void *)dupped_cmd), NULL);
	while (splitted_path[++i])
	{
		full_cmd = mycmdjoin(splitted_path[i], dupped_cmd);
		if (!full_cmd)
			return (free((void *) dupped_cmd), frall(splitted_path), NULL);
		if (access(full_cmd, R_OK | X_OK) == 0)
			return (free((void *) dupped_cmd), frall(splitted_path), full_cmd);
		free((void *) full_cmd);
	}
	frall(splitted_path);
	return (free((void *) dupped_cmd), NULL);
}

int	pseudo_execlp(const char *cmd, const char *const *envp, t_pipex *pipex)
{
	const char	*full_cmd;
	char *const	*argvs;

	if (!cmd || !envp || !pipex)
		return (-1);
	full_cmd = getcmd(cmd, envp, -1);
	if (!full_cmd)
		return (perror(cmd), -1);
	argvs = (char *const *) mysplit(cmd, ' ');
	if (!argvs)
		return (free((void *) full_cmd), -1);
	if (execve(full_cmd, argvs, (char *const *) envp) < 0)
		perror("execve");
	(free((void *) full_cmd), frall((const char **) argvs));
	(destroy(pipex), kill_std(), exit(EXIT_FAILURE));
	return (-1);
}
