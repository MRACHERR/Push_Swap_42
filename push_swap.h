#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
char    **get_list_from_arg(int argc, char **argv);
void    arg_verify(int argc, char **argv);
void    is_empty(char **argv);
void	handle_errors(char *error_msg);
void    initial_stack(int argc, char **argv, t_list **a);
#endif