/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:38:21 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/26 15:42:30 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int argc, char **argv)
{
	int		i;
	char	**list;
	int		j;

	i = 0;
	j = 0;
	list = get_list_from_arg(argc, argv);
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (ft_atoi(list[i]) > ft_atoi(list[j]))
				return (list_free(list), 0);
			j++;
		}
		i++;
	}
	return (list_free(list), 1);
}

char	**get_list_from_arg(int argc, char **argv)
{
	int		i;
	char	**list;
	char	*args;

	args = NULL;
	i = 1;
	while (i++ < argc)
	{
		args = ft_strjoin(args, argv[i]);
		if (!args)
			return (free(args), NULL);
		args = ft_strjoin(args, " ");
		if (!args)
		{
			free(args);
			handle_errors();
		}
	}
	list = ft_split(args, ' ');
	if (!list)
	{
		free(args);
		handle_errors();
	}
	return (free(args), list);
}

void	initial_stack(int argc, char **argv, t_list **a)
{
	int		i;
	char	**list;
	t_list	*new;

	list = get_list_from_arg(argc, argv);
	i = 0;
	while (list[i])
	{
		new = ft_lstnew(atoi(list[i]));
		if (!new)
			exit(1);
		new->index = 0;
		ft_lstadd_back(a, new);
		i++;
	}
	list_free(list);
}

void	get_index(t_list **a)
{
	int		max_index;
	int		max_value;
	t_list	*tmp;
	t_list	*max_node;

	max_index = ft_lstsize(*a) - 1;
	while (max_index)
	{
		tmp = *a;
		max_value = INT_MIN;
		while (tmp)
		{
			if (tmp->content > max_value && tmp->index == 0)
			{
				max_value = tmp->content;
				max_node = tmp;
			}
			tmp = tmp->next;
		}
		max_node->index = max_index;
		max_index--;
	}
}

void	sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
	}
	else if (ft_lstsize(*a) == 3)
		sort3(a);
	else if (ft_lstsize(*a) == 4)
		sort4(a, b);
	else if (ft_lstsize(*a) == 5)
		sort5(a, b);
	else
	{
		if (ft_lstsize(*a) <= 100)
			push_b(a, b, 15);
		else if (ft_lstsize(*a) > 100)
			push_b(a, b, 30);
		push_a(a, b);
	}
}
