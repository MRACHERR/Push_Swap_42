# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 12:38:44 by acherraq          #+#    #+#              #
#    Updated: 2024/05/26 12:38:45 by acherraq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCES = push_swap.c utils.c parse.c linked_list.c sorting/sort.c sorting/utils_sort.c moves/push.c moves/rot.c moves/rrot.c moves/swap.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJECTS) printf/libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) $(OBJECTS) -o push_swap -Llibft -lft -Lprintf -lftprintf

%.o : %.c push_swap.h | libft printf
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

libft:
	make -C libft

printf:
	make -C printf

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C printf clean
	
fclean: clean
	rm -f $(NAME) 
	make -C libft fclean
	make -C printf fclean
	
re: fclean all

.PHONY: all bonus libft printf clean fclean re