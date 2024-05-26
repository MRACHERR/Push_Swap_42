/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:40:57 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/26 12:40:58 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot(t_list **s)
{
	t_list	*tmp;

	if (!(*s) || !(*s)->next)
		return ;
	if (ft_lstsize(*s) > 1)
	{
		tmp = *s;
		(*s) = (*s)->next;
		tmp->next = NULL;
		ft_lstadd_back(s, tmp);
	}
}

void	ra(t_list **s)
{
	ft_printf("ra\n");
	rot(s);
}

void	rb(t_list **s)
{
	ft_printf("rb\n");
	rot(s);
}
