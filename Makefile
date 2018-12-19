# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 16:57:42 by fdikilu           #+#    #+#              #
#    Updated: 2018/12/19 19:01:58 by fdikilu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = minishell

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC =\
	check_builtin.c \
	ft_reset_env.c \
	ft_getvalue.c \
	dollar_tilde.c \
	ft_env.c \
	ft_unsetenv.c \
	ft_setenv.c \
	ft_cd.c \
	ft_echo.c \
	ft_pwd.c \
	ft_exit.c \
	ft_findinpath.c \
	ft_lexer.c \
	ft_lexer_p2.c \
	ft_exec.c \
	ft_free.c \
	minishell.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re $(LIB) $(NAME)

all: $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME)

re: fclean all
