/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allopez <allopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:55:20 by allopez           #+#    #+#             */
/*   Updated: 2021/08/30 13:21:11 by allopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

// Gerer les erreurs comme KE
// Rename/refaire la fonction freecharmatrix
// Essayer de remplacer extern char **environ par de simples char**env dans les fonctions
// Essayer de comprendre le wait


void	ft_pipex(int argc, char **argv)
{
	int		in;
	int		out;
	int		pipefd[2];
	pid_t	pid;

	in = open(argv[1], O_RDONLY);
	if (in == -1)
		ft_error("Failed opening input file or file doesn't exist.");
	out = open(argv[argc - 1], O_WRONLY);
	if (out == -1)
		ft_error("Failed opening output file or file doesn't exist");
	if (pipe(pipefd) == -1)
		ft_error("Failed to create a pipe.");
	pid = fork();
	if (pid == -1)
		ft_error("Failed to fork the process.");
	if (pid == 0)
		ft_pipeout(pipefd, out, argv[3]);
	else
		ft_pipein(pipefd, in, argv[2]);
}

void	ft_pipein(int pipefd[2], int in, char *cmd1)
{
	char	**args;

	close(pipefd[0]);
	args = ft_split(cmd1, ' ');
	if (dup2(in, 0) == -1)
		ft_error("Failed to connect infile with STDIN");
	if (dup2(pipefd[1], 1) == -1)
		ft_error("Failed to connect STDOUT with pipe's WRITE END");
	if (args[0][0] == '/')
	{
		if (execve(args[0], args, environ) == -1)
			ft_error("Invalid command address.");
	}
	else
		ft_exec(args[0], args);
	ft_freetab(args);
	close(in);
	close(pipefd[1]);
	wait(NULL);
}

void	ft_pipeout(int pipefd[2], int out, char *cmd2)
{
	char	**args;

	close(pipefd[1]);
	args = ft_split(cmd2, ' ');
	dup2(pipefd[0], 0);
	dup2(out, 1);
	if (args[0][0] == '/')
	{
		if (execve(args[0], args, environ) == -1)
			ft_error("Command address not found.");
	}
	else
		ft_exec(args[0], args);
	ft_freetab(args);
	close(out);
	close(pipefd[0]);
}

void	ft_exec(char *cmd, char **args)
{
	int		i;
	char	**paths;

	paths = NULL;
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			environ[i] += 5;
			paths = ft_split(environ[i], ':');
			break ;
		}
		i++;
	}
	ft_testpaths(cmd, args, paths);
}

void	ft_testpaths(char *cmd, char **args, char **paths)
{
	int		i;
	char	*temp;
	char	*newpath;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		newpath = ft_strjoin(temp, cmd);
		execve(newpath, args, environ);
		free(newpath);
		free(temp);
		i++;
	}
	ft_freetab(paths);
	ft_error("Command not found.");
}
