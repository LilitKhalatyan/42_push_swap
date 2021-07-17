#include "push_swap.h"

void    ft_print_stack(stack *a, char c)
{
    node *tmp;

    tmp = *a;
    while (*a)
    {
        printf(" %c = %d\n", c, (*a)->value);
        *a = (*a)->next;
    }
    *a = tmp;
}

node	*ft_lstlast(stack *lst)
{
    node *tmp;
    node *tmp1;

    tmp1 = *lst;
    tmp = *lst;
	if (!*lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
    *lst = tmp1;
	return (tmp);
}

node	*ft_lstprev(stack *lst)
{
    node *tmp;
    node *tmp1;

    tmp1 = *lst;
    tmp = *lst;
	if (!*lst)
		return (NULL);
	while (tmp->next != NULL && tmp->next->next != NULL)
		tmp = tmp->next;
    *lst = tmp1;
	return (tmp);
}

int		ft_stack_size(stack *mystack)
{
	int size;
    node *tmp;

    tmp = *mystack;
    if (!*mystack)
        return(0);
	size = 0;
	while (*mystack)
	{
		*mystack = (*mystack)->next;
		size++;
	}
    *mystack = tmp;
	return (size);
}


int ft_push(stack *mystack, int value)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
        return(1);
    newnode->next = NULL;
    newnode->value = value;
    node *tmp = *mystack;
    if (tmp)
    {
        tmp = newnode;
        tmp->next = *mystack;
        *mystack = tmp;
    }
    else
        *mystack = newnode;
    return (0);
}

int ft_pop(stack *mystack)
{
    int result;
    
    result = (*mystack)->value;
    node *temp = *mystack;
    *mystack = (*mystack)->next;
    free(temp);
    return (result);
}

int             ft_sorted_as(stack *c)
{
    node *tmp;

    tmp = *c;
	while (tmp && tmp->next != NULL)
    {
        if (tmp->value > tmp->next->value)
            return(0);
        else
		    tmp = tmp->next;
    }
	return (1);
}

int             ft_sorted_ds(stack *c)
{
    node *tmp;

    tmp = *c;
	while (tmp && tmp->next != NULL)
    {
        if (tmp->value < tmp->next->value)
            return(0);
        else
		    tmp = tmp->next;
    }
	return (1);
}

int             ft_max(stack *c)
{
    int max;
    node *tmp;

    tmp = *c;
    max = tmp->value;
	while (tmp)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
	return (max);
}

int             ft_min(stack *c)
{
    int min;
    node *tmp;

    tmp = *c;
    min = (*c)->value;
	while ((*c) && (*c)->next != NULL)
    {
        if (min > (*c)->next->value)
        {
            min = (*c)->next->value;
            (*c) = (*c)->next;
        }
        else
            (*c) = (*c)->next;
    }
    *c = tmp;
	return (min);
}

