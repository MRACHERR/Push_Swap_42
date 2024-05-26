/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:39:00 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/26 12:39:08 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stack_sorted(t_list *b)
{
	t_list	*tmp;

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

void	push_b(t_list **a, t_list **b, int del)
{
	int	i;

	i = 0;
	while (ft_lstsize(*a) > 0)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= (del + i))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

int	h_index_section(t_list **b, int h)
{
	t_list	*tmp;
	int		i;
	int		size;

	size = ft_lstsize(*b);
	tmp = *b;
	i = 0;
	while (tmp && i < size / 2)
	{
		if (tmp->index == h)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	push_a(t_list **a, t_list **b)
{
	int	h_index;

	h_index = get_h_index(*b);
	while (0 < ft_lstsize(*b))
	{
		if ((*b)->index == h_index)
		{
			pa(a, b);
			h_index--;
		}
		else if ((*b)->next->index == h_index)
		{
			sb(b);
			pa(a, b);
			h_index--;
		}
		else
		{
			if (h_index_section(b, h_index))
				rb(b);
			else
				rrb(b);
		}
	}
}
