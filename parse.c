#include <push_swap.h>

void arg_verify(int argc, char **argv)
{
    char    **list;
    int     i;
    int     j;

    list = NULL;
    list = get_list_arg(argc, argv);
    is_empty(argv);
    there_is_deplicate(list);
    i = 0;
    j = 0;
    while (list[i])
    {
        j = 0;
        if ((list[i][j] == '-' || list[i][j] == '+') && list[i][j+1])
            j++;
        while (list[i][j])
        {
            if (!ft_isdigit(list[i][j]))
                (list_free(list), handle_errors("error not digit"));
            j++;
        }
        i++;
    }
    list_free(list);

}



void is_empty(char **argv)
{
    int i;
    int j;
    int find;

    find = 0;
    j = 0;
    i = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]))
                find = 1;
        }
        if (find = 0 || !argv[i][0])
            handle_errors("empty");
        i++;
    }

}

void    there_is_deplicate(char **list)
{
    int i;
    int j;

    i = 0;
    if (ft_atoi(list[0]) < -2147483648 || ft_atoi(list[0]) > 2147483647)
		return (handle_errors("verify int input"));
    while (list[i])
    {
        j = i + 1;
        while (list[j])
        {
            
            if (ft_atoi(list[i]) == ft_atoi(list[j] 
                || (ft_atoi(str[j]) < -2147483648
                        || ft_atoi(str[j]) > 2147483647)))
                return(handle_errors("error Deplicate"));
            j++;
        }
        i++;
    }
}