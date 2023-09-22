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
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
void push(t_stack **stack, int data);
void pop(t_stack **stack);
void free_stack(t_stack *stack);
void ft_error(t_stack *stack);
int stacksize(t_stack *stack);
#endif