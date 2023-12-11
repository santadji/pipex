/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <santadji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:17:19 by santadji          #+#    #+#             */
/*   Updated: 2023/12/11 19:39:57 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_line(char **env)
{
	char	**env_line;
	char	*path_line;
	
	env_line = ft_split(env, "/0");
	if (!env_line)
		return (NULL);
	while (env_line && (ft_strncmp(env_line[i], "PATH", 4)))
		i++;
	env_line[i] = path_line;
	return (path_line);
}

char **get_all_the_paths(t_pipex *pipex, char **env)
{
	char	*path_line;
	
	path_line = get_path_line(env);
	if (!path_line)
		return (NULL);
	pipex->paths = ft_split(path_line, ':');
	if (!pipex->paths)
		return (NULL);
	return (pipex->paths);
}

