#ifndef	PUSH_SWAP_H
#define	PUSH_SWAP_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

typedef struct  node
{
    int         value;
    struct node *next;
}               node;

typedef node * stack;

////// chech errors
int				ft_str_is_numeric(char *str); //1
int		        ft_find_duplicates(int *array, int num, int c); //2
long			ft_atoi(char *str); //3
int				*ft_check_errors(stack *stack_a, int argc, char **argv); // 4
////////// fill stack 
int 			ft_push(stack *mystack, int value);
int 			ft_pop(stack *mystack);
int		        ft_stack_size(stack *lst);
node	        *ft_lstlast(stack *lst);
node	        *ft_lstprev(stack *lst);
void            ft_print_stack(stack *a, char c);
int             ft_sorted_as(stack *a);
int             ft_sorted_ds(stack *c);
int             ft_max(stack *c);
int             ft_min(stack *c);
///////// 
int             ft_sc(stack *mystack, char c);
int             ft_ss(stack *stack_a, stack *stack_b);
int             ft_pa(stack *stack_a, stack *stack_b);
int             ft_pb(stack *stack_a, stack *stack_b);
int             ft_rc(stack *mystack, char c);
int             ft_rr(stack *s_a, stack *s_b);
int             ft_rrc(stack *mystack, char c);
int             ft_rrr(stack *s_a, stack *s_b);
/////////
void            ft_correct_a(stack *a);
void            ft_other(stack *a, stack *b, int size, int chunk_size);
int             ft_check_position(int val, stack *b);
int             ft_check_position_until(int val, stack *b);
int             ft_check_position_from_max(int val, stack *b);
void            ft_rotate_b(int i, stack *a, stack *b);
void            ft_back_to_a(stack *a, stack *b);

char                **ft_split(char const *s, char c);
static unsigned int	nb_ns(char const *s, char c);
static unsigned int	ns_len(char const *s, char c);
static char			**ft_free(char **str);



#endif
