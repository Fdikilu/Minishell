/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:22:36 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/10 21:22:40 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	int		i;
	int		*test;
	char	**argv;
	char	**test_env;
	char	*line;
	char	dirTest[256];
	pid_t	retfork;

	(void)ac;
	(void)av;
	test = NULL;
	if (!(test_env = ft_reset_env(env, 0)))
		return (NULL);
	while ((1))
	{
		getcwd(dirTest, 255);
		printf("dossier courant: %s\n", dirTest);
		ft_putstr("$> ");
		get_next_line(0, &line);
		printf("---------\nline de GNL: %s\n---------\n", line);
		argv = ft_strsplit(line, ' ');
		i = 0;
		while (argv[i])
		{
			printf("argv[%d]: %s\n", i, argv[i]);
			i++;
		}
		ft_putstr("-------------\n");
		retfork = fork();
		if (retfork > 0)//si retfork=0 c kon est ds le proc pere
		{
			wait(test);	
		}
		if (retfork == 0) // si retfork == 0 s'est qu'on dans le proc fils
		{
			if ((execve(argv[0], argv, NULL)) == -1)
				perror("execve");
		}
	}
	return (0);
}
