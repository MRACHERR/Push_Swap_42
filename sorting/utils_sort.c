#include "../push_swap.h"

int is_stack_sorted(t_list *b)
{
    t_list  *tmp;

    tmp = b;
    while (tmp->next)
    {
        if (tmp->content > tmp->next->next->content)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}