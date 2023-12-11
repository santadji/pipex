/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <santadji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:42:04 by santadji          #+#    #+#             */
/*   Updated: 2023/12/11 19:36:34 by santadji         ###   ########.fr       */
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
	{
		pipex->fd_in = open(argv[1], F_OK);
		return (1);
	}
	return (0);
}

int	check_outfile(char **argv, t_pipex *pipex)
{
	pipex->fd_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (1);
}

int	check_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc < 5)
		return (0);
	if (!check_infile)
		return (0);
	if (!check_outfile)
		return (0);
	return (1);
}

int	parsing_paths(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int i;
	char	*path_envp;
	char	**cmds;

	pipex->paths = malloc(sizeof(char *) * 2);
	if (!pipex->paths)
		return (0);
	path_envp = ft_substr(envp, )
	pipex->paths = get_all_the_paths()
	i = 1;
	}

