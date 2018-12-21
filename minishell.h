/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:37:35 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/21 14:25:28 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

char	*findvar(char *env, char *name);
char	*ft_getvalue(char **env, char *name);
char	**ft_reset_env(char **env, int resize);
int		check_builtin(char *cmd);
char	*ft_findinpath(char **env, char *cmd);
void	dollar_tilde(char **env, t_list *l_cmd);
void	l_cmdfree(t_list *l_cmd);
void	ft_env(char **env);
char	**ft_unsetenv(char **env, char *name);
char	**ft_setenv(char **env, char *name, char *value);
char	**ft_cd(char **env, char **argv);
void	ft_echo(char **env, char **argv);
void	ft_pwd(char **env);
void	ft_exit(char **env, t_list *l_cmd);
t_list	*ft_lexer(char *line);
t_list	*ft_lexer_p2(char **env, char *line);
char	**ft_exec(char **env, char **argv);

#endif
