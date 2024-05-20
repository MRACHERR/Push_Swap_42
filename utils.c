#include "push_swap.h"


void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void    list_free(char **list)
{
    int i;

    i = 0;
    while (list[i])
        free(list[i++]);
    free(list);
}

int is_sorted(int   argc, char **argv)
{
    int i;
    char    **list;
    int     j;

    i = 0;
    j = 0;
    list = get_list_from_arg(argc,argv);

    while (argv[i])
    {
        j = i + 1;
        while(argv[j])
        {
            if (ft_atoi(argv[i])> ft_atoi(argv[j]))
                return (list_free(list),0);
            j++;
        }
        i++;
    }
    return(list_free(list), 1);
}

char    **get_list_from_arg(int argc, char **argv)
{
    int     i;
    char    **list;
    char    *args;

    list = NULL;
    args = NULL;
    i = 1;
    while (i < argc)
    {
        args = ft_strjoin(args, argv[i]);
        args = ft_strjoin(args, " ");
        i++;
    }
    list = ft_split(args, ' ');
    free(args);
    return(list);
}

void    initial_stack(int argc, char **argv, t_list **a)
{
    int     i;
    char    **list;
    t_list  *new;

    list = get_list_from_arg(argc, argv);
    i = 0;
    while (list[i])
    {
        new = ft_lstnew(atoi(list[i]));
        new->index = 0;
        ft_lstadd_back(a, new);
        i++;
    }
    list_free(list);    
}

void    get_index(t_list **a)
{
    int max_index;
    int max_value;
    t_list  *tmp;
    t_list  *max_node;

    max_index = ft_lstsize(*a) - 1;
    //ft_printf("%d", max_index);
    while (max_index)
    {
        tmp = *a;
        max_value = INT_MIN;
        while (tmp)
        {
            if(tmp->content > max_value && tmp->index == 0)
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

void    sort(t_list **a, t_list **b)
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
    // else
	// {
	// 	if (ft_lstsize(*a) <= 100)
	// 		push_a_to_b(a, b, 15);
	// 	else if (ft_lstsize(*a) >= 100)
	// 		push_a_to_b(a, b, 35);
	// 	turn_to_a(a, b);
	// }
}