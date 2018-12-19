/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:19:20 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/17 15:31:44 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getvalue(char **env, char *name)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], name))
		{
			tmp = ft_strchr(env[i], '=');
			tmp++;
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
