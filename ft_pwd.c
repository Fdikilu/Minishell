/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:09:27 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/19 22:29:48 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **env)
{
	int		i;
	char	buf[1025];
	char	*tmp;

	i = 0;
	if ((tmp = ft_getvalue(env, "PWD")))
	{
		ft_putstr(tmp);
		ft_putchar('\n');
		return ;
	}
	if (!(getcwd(buf, 1024)))
	{
		write(2, "pwd not found\n", 14);
		return ;
	}
	ft_putstr(buf);
	ft_putchar('\n');
}
