#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	int		size;
	t_list	*p;

	p = lst;
	i = 0;
	size = ft_lstsize(lst);
	while (i < size - 1)
	{
		p = p->next;
		i++;
	}
	return (p);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*p;

	p = lst;
	i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
