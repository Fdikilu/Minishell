# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 16:57:42 by fdikilu           #+#    #+#              #
#    Updated: 2018/12/10 03:08:38 by fdikilu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = minishell

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC =\
	ft_reset_env.c \
	ft_env.c \
	ft_unsetenv.c \
	ft_setenv.c \
	ft_cd.c \
	main.c

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
