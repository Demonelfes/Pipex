# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allopez <allopez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 11:57:37 by allopez           #+#    #+#              #
#    Updated: 2021/08/30 11:57:40 by allopez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = main.c ft_pipex.c ft_error.c ft_freetab.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./libft
	@${CC} ${OBJS} ${CFLAGS} ./libft/libft.a -o ${NAME}

clean:
	@$(MAKE) -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
