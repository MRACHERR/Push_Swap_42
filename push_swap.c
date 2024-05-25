#include "push_swap.h"

void    free_stack(t_list *list)
{
    t_list *list_free;
    t_list  *tmp;

    tmp = list;
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
    t_list *b;

    a = NULL;
    b = NULL;
    if (argc == 1)
        return (0);
    arg_verify(argc, argv);
    if (is_sorted(argc, argv))
		return (0);
    // ft_printf("s\n");
    initial_stack(argc, argv, &a);
    if (ft_lstsize(a) == 1)
        return 0;
    get_index(&a);
    sort(&a,&b);
    t_list *tmp;
    tmp = a;
    while (tmp)
    {
        ft_printf("%d\t", (tmp)->content);
        tmp = tmp->next;
    }
    free_stack(a);
}