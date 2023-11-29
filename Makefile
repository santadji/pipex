# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: santadji <santadji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 15:31:18 by santadji          #+#    #+#              #
#    Updated: 2023/11/29 15:48:50 by santadji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = pipex.c\

OBJS = &(SRCS:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(OBJS) -o $(NAME)
		@echo "pipex compiled"

clean:
		@(rm -f $(OBJS))
		@echo "pipex cleaned"

fclean:
		@(rm -f pipex)
		@(rm -f $(NAME))
		@echo "pipex full cleaned"

re: fclean all