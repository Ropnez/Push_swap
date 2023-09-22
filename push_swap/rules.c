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
    
    if (stacksize(*stack_a) > 1){
        t_stack *temp;

        temp = (*stack_a)->next;
        (*stack_a)->next = (*stack_b);
        (*stack_b) = (*stack_a);
        (*stack_a) = temp;
    }

}

void ra(t_stack **stack_a){

    if (stacksize(*stack_a) < 2)
        return ;
    t_stack *temp;
    t_stack *last;

    temp = (*stack_a);
    last = (*stack_a);
    while(last->next)
        last = last->next;
    last->next = temp;
    temp = temp ->next;
    last ->next->next = NULL;
    (*stack_a) = temp;
    
}

void rb(t_stack **stack_b){

    if (stacksize(*stack_b) < 2)
        return ;
    t_stack *temp;
    t_stack *last;

    temp = (*stack_b);
    last = (*stack_b);
    while(last->next)
        last = last->next;
    last->next = temp;
    temp = temp ->next;
    last ->next->next = NULL;
    (*stack_b) = temp;
    
}

void rr (t_stack **stack_a, t_stack **stack_b){
    ra(stack_a);
    rb(stack_b);
}

void rra(t_stack **stack_a){

    if (stacksize(*stack_a) < 2)
        return ;
    t_stack *temp;
    t_stack *last;

    temp = (*stack_a);
    last = (*stack_a);
    while(last->next)
        last = last->next;
    while(temp->next->next != NULL)
        temp = temp->next;
    last->next = (*stack_a);
    temp->next = NULL;
    (*stack_a) = last;   
}

void rrb(t_stack **stack_b){

    if (stacksize(*stack_b) < 2)
        return ;
    t_stack *temp;
    t_stack *last;

    temp = (*stack_b);
    last = (*stack_b);
    while(last->next)
        last = last->next;
    while(temp->next->next != NULL)
        temp = temp->next;
    last->next = (*stack_b);
    temp->next = NULL;
    (*stack_b) = last;   
}

void rrr (t_stack **stack_a, t_stack **stack_b){
    rra(stack_a);
    rrb(stack_b);
}