/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:09:57 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/19 21:31:07 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_builtin(char *cmd)
{
	if (ft_strcmp("echo", cmd) == 0)
		return (0);
	else if (ft_strcmp("cd", cmd) == 0)
		return (0);
	else if (ft_strcmp("pwd", cmd) == 0)
		return (0);
	else if (ft_strcmp("env", cmd) == 0)
		return (0);
	else if (ft_strcmp("setenv", cmd) == 0)
		return (0);
	else if (ft_strcmp("unsetenv", cmd) == 0)
		return (0);
	else if (ft_strcmp("exit", cmd) == 0)
		return (0);
	else
		return (1);
}
