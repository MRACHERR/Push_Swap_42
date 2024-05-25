#include "push_swap.h"

void	free_stack(t_list *list)
{
	t_list	*list_free;
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		list_free = tmp;
		tmp = tmp->next;
		free(list_free);
	}
}

void	list_free(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	arg_verify(argc, argv);
	if (is_sorted(argc, argv))
		return (0);
	initial_stack(argc, argv, &a);
	if (ft_lstsize(a) == 1)
		return (0);
	get_index(&a);
	sort(&a, &b);
	free_stack(a);
}
