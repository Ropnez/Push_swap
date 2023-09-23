#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "./libft/libft.h"

typedef struct s_stack
{
	int	data;
	struct	s_stack *next;
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
void push_init(t_stack **stack, int data);
int control(char *str);
void free_tab (char **str);
void ft_error(t_stack *stack);
void ft_push_str(t_stack **stack, char *str);
void ft_control(t_stack *stack_a, char **av, int j);
void	ft_is_one(t_stack **stack_a, t_stack **stack_b);
int	check_sort(t_stack *stack);
int	check(t_stack *stack, int data);
#endif