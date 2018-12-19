/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:22:19 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/18 23:27:00 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	l_cmdfree(t_list *l_cmd)
{
	t_list	*tmp;

	while (l_cmd)
	{
		tmp = l_cmd;
		l_cmd = l_cmd->next;
		ft_tabfree((char **)tmp->content);
		free((void *)tmp);
	}
}
