/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:53:40 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/09 21:44:17 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unsetenv(char **env, char *name)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], name))
			ft_strclr(env[i]);
		i++;
	}
	if (!(new_env = ft_reset_env(env, -1)))
		return (env);
	ft_tabfree(env);
	return (new_env);
}
