#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;
    if (argc == 1)
        return (0);
    arg_verify(argc, argv);
    if (is_sorted(argc, argv))
		return (0);
    initial_stack(argc, argv, &a);
    
}