/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <santadji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:56:09 by santadji          #+#    #+#             */
/*   Updated: 2023/12/05 18:56:42 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_strs(char	*str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	if (!new)
		exit(1);
	while (i < n && src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	free_tab(char **tab, int i, int k)
{
	if (!tab[k])
	{	
		while (i)
		{
			if (tab[i])
				free(tab[i]);
			i--;
		}
		free(tab);
	}
	return ;
}

int	split(char **strs, char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			strs[k] = ft_strndup(s + j, i - j);
			if (strs[k] == NULL)
				return (0);
			free_tab(strs, i, k);
			k++;
		}
	}
	strs[k] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**strs;
	int		count;

	if (!s)
		return (NULL);
	count = count_strs((char *)s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		exit(1);
	if (!split(strs, (char *)s, c))
	{
		i = 0;
		while (i < count)
		{
			if (strs[i])
				free(strs[i]);
			i++;
		}
		free(strs);
		return (NULL);
	}
	strs[count] = NULL;
	return (strs);
}
