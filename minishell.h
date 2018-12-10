/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:37:35 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/10 21:28:52 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

void	ft_env(char **env);
char	**ft_reset_env(char **env, int resize);
char	**ft_unsetenv(char **env, char *name);
char	**ft_setenv(char **env, char *name, char *value);

void	ft_cd(char **env, char *path);

#endif
