#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "./libft/libft.h"

typedef struct s_stack
{
    int data;
    struct s_stack *next;
}   t_stack;

void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss (t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ft_error(t_stack *stack);
int stacksize(t_stack *stack);
#endif