#include "../push_swap.h"

int is_stack_sorted(t_list *b)
{
    t_list  *tmp;

    tmp = b;
    while (tmp->next)
    {
        if (tmp->content > tmp->next->content)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int	get_h_index(t_list *s)
{
	t_list	*tmp;
	int		h;

	tmp = s;
	h = tmp->index;
	while (tmp)
	{
		if (tmp->index > h)
			h = tmp->index;
		tmp = tmp->next;
	}
	return (h);
}