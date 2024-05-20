#include "../push_swap.h"

void    rrot(t_list **s)
{
    t_list  *tmp;
    t_list  *tail;
    t_list  *new_tail;

    if (ft_lstsize(*s) > 1)
    {
        tail = get_bottom(*s);
        new_tail = get_before_bottom(*s);
        tmp = *s;
        (*s) = tail;
        (*s)->next = tmp;
        new_tail->next = NULL;
    }    
}

void    rra(t_list **s)
{
    ft_printf("rra\n");
    rrot(s);
}

void    rrb(t_list **s)
{
    ft_printf("rrb\n");
    rrot(s);
}

void    rrr(t_list **a, t_list **b)
{
    ft_printf("rrr\n");
    rrot(a);
    rrot(b);
}

/*	Returns the last element of the stack. */

t_list	*get_bottom(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* Returns de element before the bottom element */

t_list	*get_before_bottom(t_list *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}	
