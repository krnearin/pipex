/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krnearin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:05:27 by krnearin          #+#    #+#             */
/*   Updated: 2021/08/12 19:05:27 by krnearin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(char **argv, char **envp)
{
	int		pipefds[2];
	pid_t	child1;
	pid_t	child2;
	int		status;

	if (pipe(pipefds) == -1)
		ft_exit("failed to create pipe");
	child1 = fork();
	if (child1 < 0)
		ft_exit("failed fork");
	if (child1 == 0)
		ft_child_one(pipefds, argv, envp);
	child2 = fork();
	if (child2 < 0)
		ft_exit("failed fork");
	if (child2 == 0)
		ft_child_two(pipefds, argv, envp);
	close(pipefds[0]);
	close(pipefds[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	ft_child_one(int pipefds[2], char **argv, char **envp)
{
	int		in;
	char	*cmd;
	char	**cmdargv;

	cmdargv = ft_split(argv[2], ' ');
	cmd = ft_env(cmdargv[0], envp);
	if (!cmd)
		exit(0);
	close(pipefds[0]);
	dup2(pipefds[1], 1);
	close(pipefds[1]);
	in = open(argv[1], O_RDONLY);
	if (in == -1)
		ft_exit("open failed on input file");
	dup2(in, 0);
	close(in);
	execve(cmd, cmdargv, envp);
	ft_exit("error execve");
}

void	ft_child_two(int pipefds[2], char **argv, char **envp)
{
	int		out;
	char	*cmd;
	char	**cmdargv;

	cmdargv = ft_split(argv[3], ' ');
	cmd = ft_env(cmdargv[0], envp);
	if (!cmd)
		exit(0);
	out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (out == -1)
		ft_exit("open failed on output file");
	close(pipefds[1]);
	dup2(pipefds[0], 0);
	close(pipefds[0]);
	dup2(out, 1);
	execve(cmd, cmdargv, envp);
	ft_exit("error execve");
}

char	*ft_env(char *cmdd, char **envp)
{
	int		i;
	char	**new_path;
	char	*cmd;
	char	*my_path;

	new_path = ft_path(envp);
	i = -1;
	while (new_path[++i])
	{
		my_path = ft_strjoin(new_path[i], "/");
		if (!my_path)
			ft_exit("error malloc");
		cmd = ft_strjoin(my_path, cmdd);
		if (!cmd)
			ft_exit("error malloc");
		free(my_path);
		if (access(cmd, 1) == 0)
		{
			ft_free_p(new_path);
			return (cmd);
		}
	}
	ft_exit("not found command");
	return (cmd);
}

char	**ft_path(char **envp)
{
	char	**new_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	new_path = ft_split(envp[i] + 5, ':');
	return (new_path);
}
