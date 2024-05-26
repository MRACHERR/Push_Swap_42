/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:41:01 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/26 12:41:02 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrot(t_list **s)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*new_tail;

	if (!(*s) || !(*s)->next)
		return ;
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

void	rra(t_list **s)
{
	ft_printf("rra\n");
	rrot(s);
}

void	rrb(t_list **s)
{
	ft_printf("rrb\n");
	rrot(s);
}

t_list	*get_bottom(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_list	*get_before_bottom(t_list *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
