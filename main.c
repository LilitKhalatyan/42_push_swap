#include "push_swap.h"

int main(int argc, char **argv)
{
    int     len;
    int     size;
	//char    **array;
    int     *array;
    stack   a;
    stack   b;

    len = argc - 1;
    array = ft_check_errors(&a, argc, argv);
	if (!array)
       write(1, "Error!!\n", 7);
    size = ft_stack_size(&a);
    if (size <= 1 || ft_sorted_as(&a) == 1)
        return(0);
    else if (size <= 5)
        ft_other(&a, &b, size, 2);
    else
        ft_other(&a, &b, size, 19);
    ft_other(&a, &b, size, 19);
    return(0);
}
    //       126 9 24 16 78 91 140 7 46 25 2 86 102
    // ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./a.out $ARG | wc -l
