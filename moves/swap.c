/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:41:04 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/26 12:41:37 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **s)
{
	t_list	*p1;
	t_list	*p2;

	p1 = NULL;
	p2 = NULL;
	if ((*s && (*s)->next) || !s)
	{
		p1 = *s;
		*s = (*s)->next;
		p1->next = NULL;
		p2 = *s;
		*s = (*s)->next;
		p2->next = NULL;
		ft_lstadd_front(s, p1);
		ft_lstadd_front(s, p2);
	}
}

void	sa(t_list **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_list **b)
{
	ft_printf("sb\n");
	swap(b);
}
