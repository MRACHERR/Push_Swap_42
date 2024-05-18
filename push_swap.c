#include "push_swap.h"

void    free_stack(t_list *list)
{
    t_list *list_free;
    t_list  *tmp;

    list_free = list;
    while(tmp)
    {
        list_free = tmp;
        tmp = tmp->next;
        free(list_free);
    }
}

int main(int argc, char **argv)
{
    t_list *a;
    //t_list *b;

    a = NULL;
    //b = NULL;
    if (argc == 1)
        return (handle_errors("invalid argument"),0);
    arg_verify(argc, argv);
    if (is_sorted(argc, argv))
		return (0);
    initial_stack(argc, argv, &a);
    get_index(&a);
    //sort(&a,&b);
    free_stack(a);
}