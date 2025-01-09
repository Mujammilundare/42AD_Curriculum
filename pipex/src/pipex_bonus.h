/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:00:15 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:29:56 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//TODO better execlp

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <limits.h>
# include "get_next_line.h"

# define USAGE_MAN "Usage for mandatory:\n./pipex infile cmd1\
 cmd2 outfile\n\nExample:\n./pipex infile \"ls -l\" \"wc -l\" \
 outfile\nBehaves exactly as:\n< infile ls -l | wc -l > outfile\n"
# define USAGE "Usage for bonus:\n./pipex infile cmd1 cmd 2 ... cmd(n) \
outfile\n\nExample:\n./pipex infile \"ls -l\" \"cat\" \"wc -l\" outfile\nBehaves\
 as:\n< infile ls -l | cat | wc -l > outfile\n"
# define USAGE2 "./pipex here_doc delimiter cmd1 cmd2 outfile\n"
# define USAGE3 "Behaves as:\n<< delimiter cmd1 | cmd2 >> outfile\n"
# define X_ENV "PATH="
# define F_ENV "XDG_DATA_DIRS="

typedef struct s_pipex
{
	int			bonus_type;
	int			pfd[2];
	int			mp[2];
	int			piperetval;
	int			ifd;
	int			outfilefd;
	pid_t		fork_doc;
	pid_t		fork_mid;
	pid_t		fork_first;
	pid_t		fork_last;
	int			status;
	int			num_forks;
	const char	*cmd;
	const char	*infile_path;
	int			docpipe[2];
	char		*docbuf;
	int			errn;
}	t_pipex;

typedef enum e_bonus_type
{
	HERE_DOC,
	PIPE
}	t_bonus_type;

# ifndef SILENCE_SYSCALLS
#  define SILENCE_SYSCALLS 0
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

// Misc tools
void		frall(const char **arrays);

// Splitting tools
const char	**mysplit(const char *s, char c);
void		freeall(const char **p, size_t index);
int			mystrlcpy(char *dst, const char *src, unsigned int buf_size);

//String tools
char		*mystrjoin(const char *s1, const char *s2);
int			mystrncmp(const char *s1, const char *s2, int n);
int			putstr_fd(const char *s, int fd);
int			mystrnstr(const char *haystack, const char *needle, int len);
size_t		mystrlen(const char *str);
const char	*mystrdup(const char *s);
const char	*mystrndup(const char *s, int n);
int			len_till_space(const char *s);
const char	*mycmdjoin(const char *s1, const char *s2);
int			is_absolute_path(const char *str);

// Struct tools
int			destroy(t_pipex *pipex);
void		init_pipex_fds(int argc, const char *const *argv, t_pipex *pipex);
void		clean_pipex_start(const int argc, const char *const *argv,
				t_pipex *pipex);
int			kill_std(void);

// File descriptor tools
int			is_open_fd(int fd);
int			is_writable_fd(int fd);
int			is_readable_fd(int fd);

// Debuggable syscall tools
int			bclose(int *fd);
int			better_free(void **p);
ssize_t		better_write(const int fd,
				const void *const buf, const size_t bytecount);
int			is_illegal_memory(const void *p);
int			better_pipe(int pfd[2]);
int			better_open(const char *path, int flags, mode_t mode,
				int *fd_to_set);
int			better_fork(int *forkval);
int			better_dup2(int oldfd, int newfd);

//Error detection
int			allspacesdetect(int argc, const char *const *argv);

//Execution tools
const char	*path_finder(const char *const *envp);
int			pseudo_execlp(const char *cmd,
				const char *const *envp, t_pipex *pipex);
const char	*getcmd(const char *cmd, const char *const *envp, int i);
void		exec_cmds(int argc, const char *const *argv,
				const char *const *envp, t_pipex *pipex);
void		exec_cmd_first(int argc, const char *const *argv,
				const char *const *envp, t_pipex *pipex);
void		exec_mid_cmds(const int argc, const char *const *argv,
				const char *const *envp, t_pipex *pipex);
void		exec_cmd_last(int argc, const char *const *argv,
				const char *const *envp, t_pipex *pipex);
void		exec_heredoc(const int argc, const char *const *argv,
				const char *const *envp, t_pipex *pipex);
void		exec_doc_1(const int argc, const char *const *argv,
				const char *const *envp, t_pipex *pipex);
void		exec_doc_2(const int argc, const char *const *argv,
				const char *const *envp, t_pipex *pipex);
char		*get_heredoc_buf(const char *const delimiter);
const char	*dupcmd(const char *cmd);
int			heredoc_buf(const char *const delimiter, int fd);

#endif
