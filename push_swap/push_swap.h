/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:59:15 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 19:07:13 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);
void	push(t_stack **stack, int data);
void	pop(t_stack **stack);
void	free_stack(t_stack *stack);
void	ft_error(t_stack *stack);
int		stacksize(t_stack *stack);
void	push_init(t_stack **stack, int data);
int		control(char *str);
void	free_tab(char **str);
void	ft_error(t_stack *stack);
void	ft_push_str(t_stack **stack, char *str);
void	ft_control(t_stack *stack_a, char **av, int j);
void	ft_is_one(t_stack **stack_a, t_stack **stack_b);
int		check_sort(t_stack *stack);
int		check(t_stack *stack, int data);
void	ft_sort(t_stack **a, t_stack **b, int len);
void	sort_three_a_i(t_stack **a, t_stack **b, int len);
void	sort_three_a(t_stack **a, t_stack **b, int len);
void	sort_small_b_i(t_stack **b, t_stack **a, int len);
void	sort_small_b(t_stack **b, t_stack **a, int len);
int		is_sorted(t_stack **stack, char flag, int len);
void	sort_three_first(t_stack **stack);
void	ft_sort_int_tmp(int *tmp_stack, int size);
int		find_middle(int *pivot, t_stack **stack_a, int len);
int		sort_a(t_stack **a, t_stack **b, int len, int count);
int		sort_b(t_stack **b, t_stack **a, int len, int count);
void	ft_sort(t_stack **a, t_stack **b, int len);
size_t	ft_stacksize(t_stack *stack);
void	space_ctrl(char *str);
void	argv_checker(t_stack **stack_a, t_stack **stack_b, char *str);
void	ft_instructions(t_stack **a, t_stack **b);
void	run_rules(char *rule, t_stack **a, t_stack **b);
void	free_error(char *rule, t_stack **a, t_stack **b);
void	ft_push_loop(t_stack **stack_a, char **av, int j, int ac);
void	ft_push_normal(t_stack **stack, char *str);
void	ft_push_str(t_stack **stack, char *str);
#endif