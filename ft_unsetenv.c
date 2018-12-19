/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:53:40 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/19 23:05:49 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unsetenv(char **env, char *name)
{
	int		i;
	int		do_next;
	char	**new_env;

	if (!name)
	{
		write(2, "unsetenv: Not enough parameter\n", 31);
		return (env);
	}
	i = 0;
	do_next = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], name))
		{
			do_next = 1;
			ft_strclr(env[i]);
		}
		i++;
	}
	if (!do_next)
	{
		write(2, "unsetenv: This variable does not exist\n", 39);
		return (env);
	}
	if (!(new_env = ft_reset_env(env, -1)))
		return (env);
	ft_tabfree(env);
	return (new_env);
}
