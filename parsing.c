/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <santadji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:42:04 by santadji          #+#    #+#             */
/*   Updated: 2024/01/12 11:37:38 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	parsing(int argc, char **argv, char **envp)
// {
// 	char	*path_envp;
// 	char	**paths;
// 	char	**cmds;

// 	path_envp = ft_substr(envp, 0, ft_strlen(envp));
// 	paths = ft_split(path_envp, ":");
// 	cmds = ft_split(argv[2], " ");
// }

int	check_infile(char **argv, t_pipex *pipex)
{
	if (access(argv[1], F_OK) == 0)
		pipex->fd_in = open(argv[1], O_RDONLY);
	return (pipex->fd_in);
}

int	check_outfile(char **argv, t_pipex *pipex)
{
	pipex->fd_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (pipex->fd_out);
}

int	check_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc < 5)
		return (0);
	if (!check_infile(argv, pipex) == -1)
		return (0);
	if (!check_outfile(argv, pipex) == -1)
		return (0);
	return (1);
}

int	parsing_paths(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int 	i;
	char	**cmds;

	pipex->paths = malloc(sizeof(char *) * argc - 2);
	if (!pipex->paths)
		return (0);
	pipex->paths = get_all_the_paths(pipex, envp);
	if (!pipex->paths)
		return (0);
	
	return (1);
}

int	parsing_cmds(int argc, char **argv, t_pipex *pipex)
{
	int		i;
	char	**cmds;

	pipex->cmds = malloc(sizeof(char **) * argc - 2);
	if (!pipex->cmds)
		return (0);
	i = 2;
	while (i < argc - 1)
	{
		cmds = ft_split(argv[i], ' ');
		if (!cmds)
		{
			free(pipex->cmds);
			pipex->cmds = NULL;
			return (0);
		}
		pipex->cmds[i - 2] = cmds;
		i++;
	}
	return (1);
}

