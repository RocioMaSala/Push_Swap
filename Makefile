# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/02 17:55:29 by romarti2          #+#    #+#              #
#    Updated: 2026/03/02 17:56:48 by romarti2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c  \



      get_next_line_utils.c \ 

OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

%.o: %.c Makefile push_swap.h
	@echo "Compiling: $<"
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re 
