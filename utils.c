#include <push_swap.h>


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
    i = 0;
    while (i < argc)
    {
        args = ft_strjoin(args, argv[i]);
        args = ft_strjoin(args, " ");
    }
    list = ft_split(args, ' ');
    free(args);
    return(list);
}

void    initial_stack(int argc, char **argv, t_list **a)
{
    
}