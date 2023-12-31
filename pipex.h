/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <santadji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:20:52 by santadji          #+#    #+#             */
/*   Updated: 2023/12/05 20:39:33 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct	s_pipex
{
	int	fd_in;
	int	ft_out;
	char	**paths;
	char	**cmds;
	int		cmd_counter;
} t_pipex;

#endif