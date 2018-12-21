/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:53:40 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/21 14:26:44 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	varclr(char **env, char *name)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (findvar(env[i], name))
		{
			ft_strclr(env[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

char		**ft_unsetenv(char **env, char *name)
{
	char	**new_env;

	if (!name)
	{
		write(2, "unsetenv: Not enough parameter\n", 31);
		return (env);
	}
	if (!varclr(env, name))
	{
		write(2, "unsetenv: This variable does not exist\n", 39);
		return (env);
	}
	if (!(new_env = ft_reset_env(env, -1)))
		return (env);
	ft_tabfree(env);
	return (new_env);
}
