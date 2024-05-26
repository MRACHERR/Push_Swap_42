/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:40:52 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/26 12:40:53 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **scr, t_list **dst)
{
	t_list	*n_push;

	if (!scr || !dst || !(*scr))
		return ;
	n_push = *scr;
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
