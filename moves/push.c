#include "../push_swap.h"

void	push(t_list **scr, t_list **dst)
{
	t_list	*n_push;

	n_push = *scr;
	if (n_push == NULL)
		return ;
	*scr = (*scr)->next;
	n_push->next = NULL;
	ft_lstadd_front(dst, n_push);
}

void	pa(t_list **a, t_list **b)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_list **a, t_list **b)
{
	ft_printf("pb\n");
	push(a, b);
}