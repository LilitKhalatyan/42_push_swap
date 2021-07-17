#include "push_swap.h"

void        ft_back_to_a(stack *a, stack *b)
{
    int j;

    j = 0;
    if (!(ft_sorted_ds(b)))
    {
        j = ft_check_position_from_max(ft_max(b), b);
        ft_rotate_b(j, a, b);
    }
    while (*b != NULL)
    {
        ft_pa(a, b);
    }
}

void            ft_correct_a(stack *a)
{
    int len;

    len = ft_stack_size(a);


    if ((ft_sorted_as(a) == 0 && ft_stack_size(a) > 1))
    {
        if ((*a)->value > ft_lstlast(a)->value)
            ft_rc(a, 'a');
        else if ((*a)->value > (*a)->next->value)
            ft_sc(a, 'a');
    }
}

void    ft_correct_b(stack *a, stack *b)
{
    int i;

    i = 0;
    if (ft_stack_size(b) == 0) //////// 1
        ft_pb(a, b);
    else if (ft_stack_size(b) == 1)
    {
        if (((*a)->value > (*b)->value))////////  2
        {
            ft_pb(a, b);
        }
        else if ((*a)->value < (*b)->value)//////// 3
        {
            ft_pb(a, b);
            ft_rrc(b, 'b');
        }
    } 
    else if (ft_sorted_ds(b))
    {
        if ((*a)->value > ft_max(b))
        {
            ft_pb(a, b);
        } 
        else if ((*a)->value < ft_min(b))//////// 4
        {
            ft_pb(a, b);
            ft_rc(b, 'b');       
        }
        else //////// 5
        {
            i = ft_check_position((*a)->value, b);
            ft_rotate_b(i, a, b);
        }
    }
    else if (!(ft_sorted_ds(b))) ////// not sorted
    {
        if ((*a)->value < (*b)->value)
        {
            i = ft_check_position_until((*a)->value, b);
            ft_rotate_b(i, a, b);
        }
        else
        {
            i = ft_check_position_from_max((*a)->value, b);
            ft_rotate_b(i, a, b);
        }
    }
}

void    ft_chunk_maker(int *chunk, int size, int chunk_size)
{
    int i;

    i = 0;
    while (i < chunk_size)
    {
        chunk[i] = (size / chunk_size) * (i + 1);
        i++;
    }
    chunk[--i] = size;
}


void        ft_other(stack *a, stack *b, int size, int chunk_size)
{
    int *chunk;
    int i;

    chunk = malloc(sizeof(int) * chunk_size);
    ft_chunk_maker(chunk, size, chunk_size);
    i = 0;
    while (i < size)
    {
        if ((*a)->value > chunk[7] && (*a)->value < chunk[10])
            ft_correct_b(a, b);
        else
            ft_rrc(a, 'a');
        i++;
    }
    i = 0;
    while (i < size - chunk[2])
    {
        if ((*a)->value > chunk[6] && (*a)->value < chunk[11])
            ft_correct_b(a, b);
        else
            ft_rrc(a, 'a');
        i++;
    }
    i = 0;
    while (i < size - chunk[4])
    {
        if ((*a)->value > chunk[5] && (*a)->value < chunk[12])
            ft_correct_b(a, b);
        else
            ft_rrc(a, 'a');
        i++;
    }
    i = 0;
    while (i < size - chunk[6])
    {
        if ((*a)->value > chunk[4] && (*a)->value < chunk[13])
            ft_correct_b(a, b);
        else
            ft_rrc(a, 'a');
        i++;
    }
    i = 0;
    while (i < size - chunk[8])
    {
        if ((*a)->value > chunk[3] && (*a)->value < chunk[14])
            ft_correct_b(a, b);
        else
            ft_rrc(a, 'a');
        i++;
    }
    i = 0;
    while (i < size - chunk[10])
    {
        if ((*a)->value > chunk[2] && (*a)->value < chunk[15])
            ft_correct_b(a, b);
        else
            ft_rrc(a, 'a');
        i++;
    }
    i = 0;
    while (i <= size - chunk[12])
    {
        if ((*a)->value > chunk[1] && (*a)->value < chunk[16])
            ft_correct_b(a, b);
        else
            ft_rrc(a, 'a');
        i++;
    }
    i = 0;
    while (i <= size - chunk[14])
    {
        if ((*a)->value > chunk[0] && (*a)->value < chunk[17])
            ft_correct_b(a, b);
        else
            ft_rrc(a, 'a');
        i++;
    }
    while (*a)
        ft_correct_b(a, b);
    ft_back_to_a(a, b);
    // ft_print_stack(a, 'a');
    // ft_print_stack(b, 'b');
}
