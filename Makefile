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




# push: server.o minitalk.h printf/libftprintf.a libft/libft.a
# 	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lprintf -lftprintf

# client: client.o minitalk.h printf/libftprintf.a libft/libft.a
# 	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lprintf -lftprintf

# server_bonus: server_bonus.o minitalk_bonus.h printf/libftprintf.a libft/libft.a
# 	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lprintf -lftprintf

# client_bonus: client_bonus.o minitalk_bonus.h printf/libftprintf.a libft/libft.a
# 	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lprintf -lftprintf
	
# %.o: %.c | libft printf
# 	$(CC) -c $(CFLAGS) $<

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