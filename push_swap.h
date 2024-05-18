#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
char    **get_list_from_arg(int argc, char **argv);
void    arg_verify(int argc, char **argv);
void    is_empty(char **argv);
void	handle_errors(char *error_msg);
void    initial_stack(int argc, char **argv, t_list **a);
t_list *ft_lstnew(int content);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstlast(t_list *lst);
int ft_lstsize(t_list *lst);
void    free_stack(t_list *list);
int is_sorted(int   argc, char **argv);
void    get_index(t_list **a);
void    there_is_deplicate(char **list);
void    list_free(char **list);
#endif