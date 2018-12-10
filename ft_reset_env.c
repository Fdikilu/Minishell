/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:29:28 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/10 02:30:00 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

static char	**realloc_env(int resize, int len)
{
	char	**new_env;

	if (resize == 0)
	{
		if (!(new_env = (char **)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
		new_env[len] = 0;
	}
	else if (resize == 1)
	{
		if (!(new_env = (char **)malloc(sizeof(char *) * (len + 2))))
			return (NULL);
		new_env[len + 1] = 0;
	}
	else
	{
		if (!(new_env = (char **)malloc(sizeof(char *) * (len))))
			return (NULL);
		new_env[len - 1] = 0;
	}
	return (new_env);
}

static int	fill_env(char **env, char **new_env, int setenv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i][0] != '\0')
		{
			if (!(new_env[j] = ft_strdup(env[i])))
			{
				ft_tabfree(new_env);
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i < setenv)
		new_env[i] = "insert here";
	return (1);
}

char		**ft_reset_env(char **env, int resize)
{
	int		len;
	char	**new_env;

	len = 0;
	while (env[len])
		len++;
	if (!(new_env = realloc_env(resize, len)))
		return (NULL);
	if (!fill_env(env, new_env, len + resize))
		return (NULL);
	return (new_env);
}
