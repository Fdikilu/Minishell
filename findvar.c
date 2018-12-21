/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findvar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:16:13 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/21 15:55:57 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*findvar(char *env, char *name)
{
	int		len;
	char	*var;
	char	*tmp;

	if (env[0] != name[0])
		return (NULL);
	len = ft_strlen(name);
	if (!(var = ft_strnew(len + 1)))
		return (NULL);
	ft_strcpy(var, name);
	var[len] = '=';
	tmp = ft_strstr(env, var);
	ft_strdel(&var);
	return (tmp);
}
