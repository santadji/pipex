/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <santadji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:51:48 by santadji          #+#    #+#             */
/*   Updated: 2023/12/11 19:19:25 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*pipex_init(t_pipex *pipex)
{
	pipex->fd_in = -1;
	pipex->ft_out = -1;
	pipex->paths = NULL;
	pipex->cmds = NULL;
	pipex->cmd_counter = 0;
}

void	child_one_process(int f1, char *cmd1)
{
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(f1);
	exit(EXIT_FAILURE);
}

void	child_two_process(int f2, char *cmd2)
{
	int status;
	
	waitpid(-1, &status, 0);
	dup2(f2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(f2);
	exit(EXIT_FAILURE);
}

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	int		end[2];
	int		status;
	pid_t	pid_1;
	pid_t	pid_2;

	pipe(end);
	pid_1 = fork();
	if (pid_1 == -1)
		return (perror("Fork: "));
	if (pid == 0)
		child_one_process(f1, cmd1);
	pid_2 = fork();
	if (pid_2 == -1)
		return (perror("Fork: "));
	if (pid_2 == 0)
		child_two_process(f2, cmd2);
	close(end[0]);
	close(end[1]);
	waitpid(pid_1, &status, 0);
	waitpid(pid_2, &status, 0);
	}

int main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (0);
	pipex_init(pipex);
	if (!check_args(argv))
		return (0);
	
	pipex(f1, f2, argv, env);
	return (0);
}