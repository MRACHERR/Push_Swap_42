/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:38:29 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/26 12:38:30 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <unistd.h>

char	**get_list_from_arg(int argc, char **argv);
void	arg_verify(int argc, char **argv);
void	is_empty(char **argv);
void	handle_errors(char *error_msg);
void	initial_stack(int argc, char **argv, t_list **a);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	free_stack(t_list *list);
int		is_sorted(int argc, char **argv);
void	get_index(t_list **a);
void	there_is_deplicate(char **list);
void	list_free(char **list);
void	sort(t_list **a, t_list **b);
void	sort3(t_list **a);
void	sort5(t_list **a, t_list **b);
void	push(t_list **scr, t_list **dst);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
int		is_stack_sorted(t_list *b);
void	sa(t_list **a);
void	sort4(t_list **a, t_list **b);
void	sort5(t_list **a, t_list **b);
void	ra(t_list **s);
void	rb(t_list **s);
void	rr(t_list **a, t_list **b);
void	rot(t_list **s);
void	rra(t_list **s);
void	rrb(t_list **s);
void	rrr(t_list **a, t_list **b);
void	rrot(t_list **s);
t_list	*get_before_bottom(t_list *stack);
t_list	*get_bottom(t_list *stack);
int		get_h_index(t_list *s);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b, int del);
void	sb(t_list **b);
int		h_index_section(t_list **b, int h);
int		arg_verification(int argc, char **argv);
#endif