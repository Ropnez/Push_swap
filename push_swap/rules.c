#include "push_swap.h"
#include <stdio.h>

void swap(t_stack **stack){
    t_stack *temp;

    temp = (*stack)-> next;
    (*stack)->next = temp ->next;
    temp->next = (*stack);
    (*stack) = temp;
}

void sa(t_stack **stack_a){

    if (stacksize(*stack_a) > 1)
        swap(stack_a);
}

void sb(t_stack **stack_b){

    if (stacksize(*stack_b) > 1)
        swap(stack_b);
}

void ss (t_stack **stack_a, t_stack **stack_b){
    sa(stack_a);
    sb(stack_b);
}

void pa(t_stack **stack_a, t_stack **stack_b){
    t_stack *temp;

    if (!(*stack_b))
        return ;
    temp = (*stack_b)->next;
    (*stack_b)->next = (*stack_a);
    (*stack_a) = (*stack_b);
    (*stack_b) = temp;
}

void pb(t_stack **stack_a, t_stack **stack_b){
    t_stack *temp;

    if (!(*stack_a))
        return ;
    temp = (*stack_a)->next;
    (*stack_a)->next = (*stack_b);
    (*stack_b) = (*stack_a);
    (*stack_a) = temp;

}

void ra(t_stack **stack_a){
    if (!(*stack_a))
        return ;
    
}