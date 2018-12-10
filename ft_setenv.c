/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:16:51 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/10 05:36:21 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*setvar(char *name, char *value)
{//free name et value en fonction de la maniere dont je le gere
	int		len;
	char	*var;

	len = ft_strlen(name) + ft_strlen(value) + 1;
	if (!(var = ft_strnew(len)))
		return (NULL);
	len = ft_strlen(name);
	ft_strcpy(var, name);
	var[len] = '=';
	ft_strcpy(&var[len + 1], value);
	return (var);
}

static char	**add_var(char **env, char *name, char *value)
{
	int		i;
	char	**new_env;

	i = 0;
	if (!(new_env = ft_reset_env(env, 1)))
		return (env);
	while (new_env[i])
	{
		if (ft_strcmp(new_env[i], "insert here") == 0)
		{
			if (!(new_env[i] = setvar(name, value)))
			{
				new_env[i] = 0;
				ft_tabfree(new_env);
				return (env);
			}
		}
		i++;
	}
	ft_tabfree(env);
	return (new_env);
}

char		**ft_setenv(char **env, char *name, char *value)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], name))
		{
			if (!(tmp = setvar(name, value)))
				return (env);
			free((void *)env[i]);
			env[i] = tmp;
			return (env);
		}
		i++;
	}
	return (add_var(env, name, value));
}
