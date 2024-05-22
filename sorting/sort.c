#include "../push_swap.h"

void sort3(t_list **a)
{
    int h_index;

    h_index = get_h_index(*a);
    // ft_printf("%d", h_index);
    if ((*a)->index == h_index)
        ra(a);
    else
    {
        if ((*a)->next->index == h_index)
            rra(a);
    }
    if ((*a)->index > (*a)->next->index)
        sa(a);
}

void sort4(t_list **a, t_list **b)
{
    int count;
    int i;
    int size;

    count = 0;
    i = 0;
    size = ft_lstsize(*a);
    while ((size - count > 3) && i < size)
    {
        if ((*a)->index < 1)
        {
            pb(a, b);
            count++;
        }
        else
            ra(a);
        i++;
    }
    sort3(a);
    pa(a, b);
}

void sort5(t_list **a, t_list **b)
{
    int count;
    int i;
    int size;

    count = 0;
    i = 0;
    size = ft_lstsize(*a);
    while ((size - count > 3) && i < size)
    {
        if ((*a)->index < 2)
        {
            pb(a, b);
            count++;
        }
        else
            ra(a);
        i++;
    }
    sort3(a);
    if (is_stack_sorted(*b))
        rb(b);
    pa(a, b);
    pa(a, b);
}