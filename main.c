/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <santadji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:51:48 by santadji          #+#    #+#             */
/*   Updated: 2024/01/12 11:14:51 by santadji         ###   ########.fr       */
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

int main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (0);
	pipex_init(pipex);
	if (!check_args(argv))
		return (0);
	if (!parsing_paths(argc, argv, envp, pipex))
		return (0);
	if (!parsing_cmds(argc, argv, pipex))
		return (0);
	pipex(f1, f2, argv, env);
	return (0);
}