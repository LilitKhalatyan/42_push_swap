#include "push_swap.h"

int             ft_check_position(int val, stack *b)
{
	int i = 1;
	node *tmp;

    tmp = *b;
	while(val < (*b)->value)
	{
		i++;
		(*b) = (*b)->next;
	}
	*b = tmp;
	return(i);
}

int             ft_check_position_until(int val, stack *b)
{
	int i = 1;
	node *tmp;
	int max  = ft_max(b);

    tmp = *b;
	while (val < (*b)->value && (*b)->value != max)
	{
		(*b) = (*b)->next;
		i++;
	}
	*b = tmp;
//	printf("my  dddddddddddddddddd i%d", i);
	return(i);
}

int             ft_check_position_from_max(int val, stack *b)
{
	int i = 1;
	node *tmp;
	int max  = ft_max(b);

    tmp = *b;
	while ((*b)->value != max)
	{
		(*b) = (*b)->next;
		i++;
	}
	while(*b && val < (*b)->value)
	{
		(*b) = (*b)->next;
		i++;
	}
	*b = tmp;
//	printf("my  === i%d", i);
	return(i);
}

void	ft_rotate_b(int i, stack *a, stack *b)
{
	//printf("<<<<<<<<<<i = >>>>>>>>>>%d\n", i);
	//printf("<<<<<<<<<<size/2 = >>>>>>>>>>%d\n", ft_stack_size(b) / 2);
	if (i < (ft_stack_size(b) / 2))
	{
		while (i - 1 > 0)
		{
			//printf("<<<<<<<<what>>>>>>%d\n", i);
			ft_rc(b, 'b');
		i--;
		}
	}    
	else
	{
		while (ft_stack_size(b) - i + 1> 0)
		{
			//printf("<<<<<<<< must do >>>>>>%d\n", i);
			ft_rrc(b, 'b');
			i++;
		}
	}
	ft_pb(a, b);
	// ft_print_stack(a, 'a');
	// ft_print_stack(b, 'b');  
}