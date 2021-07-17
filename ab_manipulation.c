#include "push_swap.h"

// ===  ft_sc  === swap c - swap the first 2 elements at the top of stack c. 
//Do nothing if there is only one or no elements).
int ft_sc(stack *mystack, char c)
{
    int temp;
    
    if (ft_stack_size(mystack) > 1)
    {
        temp = (*mystack)->next->value;
        (*mystack)->next->value = (*mystack)->value;
        (*mystack)->value = temp;
    }
    if (c == 'a')
        write(1, "sa\n", 3);
    else
        write(1, "sb\n", 3);
    return (1);
}

int ft_ss(stack *stack_a, stack *stack_b)
{
    int temp;
    
    if (ft_stack_size(stack_a) > 1)
    {
        temp = (*stack_a)->next->value;
        (*stack_a)->next->value = (*stack_a)->value;
        (*stack_a)->value = temp;
    }
    if (ft_stack_size(stack_b) > 1)
    {
        temp = (*stack_b)->next->value;
        (*stack_b)->next->value = (*stack_b)->value;
        (*stack_b)->value = temp;
    }
    write(1, "ss\n", 3);
    return (1);
}

// ===  ft_pa  === push a - take the first element at the top of b and put it at the top of a. Do
//nothing if b is empty.
int ft_pa(stack *stack_a, stack *stack_b)
{
    int temp;

    temp = 0;
    if (*stack_b != NULL)
    {
        temp = ft_pop(stack_b);
        ft_push(stack_a, temp);
    }
    write(1, "pa\n", 3);
    return (1);
}
// ===  ft_pb  === push b - take the first element at the top of a and put it at the top of b. 
//Do nothing if a is empty.
int ft_pb(stack *stack_a, stack *stack_b)
{
    int temp;

    temp = 0;
    //ft_push(stack_b, temp);
    if (*stack_a != NULL)
    {
        temp = ft_pop(stack_a);
        ft_push(stack_b, temp);
    }
    write(1, "pb\n", 3);
    return (1);
}
//rc : rotate a - shift up all elements of stack a by 1. 
//The first element becomes the last one.
int ft_rc(stack *mystack, char c)
{
    node *last;
    node *temp = *mystack;
    if (ft_stack_size(mystack) > 1)
    {
        last = ft_lstlast(&temp);
        *mystack = (*mystack)->next;
        last->next = temp;
        temp->next = NULL;
    }
    if (c == 'a')
        write(1, "ra\n", 3);
    else
        write(1, "rb\n", 3);
    return (1);
}

int ft_rr(stack *s_a, stack *s_b)
{
    node *last;
    node *temp = *s_a;
    node *temp1 = *s_b;

    if (ft_stack_size(s_a) > 1)
    {
        last = ft_lstlast(&temp);
        *s_a = (*s_a)->next;
        last->next = temp;
        temp->next = NULL;
    }

    if (ft_stack_size(s_b) > 1)
    {
        last = ft_lstlast(&temp);
        *s_b = (*s_b)->next;
        last->next = temp;
        temp->next = NULL;
    }
    write(1, "rr\n", 3);
    return (1);
}
//===  ft_rrc  === reverse rotate c - shift down all elements of stack a by 1. 
//The last element becomes the first one.
int ft_rrc(stack *mystack, char c)
{
    node *last;
    node *prev;

    if (ft_stack_size(mystack) > 1)
    {
        prev = ft_lstprev(mystack);
        last = ft_lstlast(mystack);
        prev->next = NULL;
        last->next = *mystack;
        *mystack = last;
    }
    if (c == 'a')
        write(1, "rra\n", 4);
    else
        write(1, "rrb\n", 4);
    return (1);
}

int ft_rrr(stack *s_a, stack *s_b)
{
    node *last;
    node *prev;

    if (ft_stack_size(s_a) > 1)
    {
        prev = ft_lstprev(s_a);
        last = ft_lstlast(s_a);
        prev->next = NULL;
        last->next = *s_a;
        *s_a = last;
    }
    if (ft_stack_size(s_b) > 1)
    {
        prev = ft_lstprev(s_b);
        last = ft_lstlast(s_b);
        prev->next = NULL;
        last->next = *s_b;
        *s_b = last;
    }
    write(1, "rrr\n", 4);
    return (1);
}
