#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int stacksize(t_stack *stack)
{
    int i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return i;
}

void ft_error(t_stack *stack){
    write(2, "error\n", 6);
    t_stack *tmp;

    while (stack)
    {
        tmp = stack;
        stack = (stack)->next;
        free(tmp);
    }
    exit(0);
}

void free_tab (char **str){
    int i = 0;
    while (str[i]){
        free (str[i]);
        i++;
    }
    free(str);
}

void free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        tmp = stack;
        stack = (stack)->next;
        free(tmp);
    }
}

void pop(t_stack **stack){
    
    t_stack *temp;
    if (!(*stack))
        return ;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

void push(t_stack **stack, int data){
    t_stack *new;

    if (!(*stack))
    {
        *stack = malloc(sizeof(t_stack));
        if (!(*stack))
            ft_error(*stack);
        (*stack)->data = data;
        (*stack)->next = NULL;
        return ;
    }
    t_stack *tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    new = malloc(sizeof(t_stack));
    if (!new)
        ft_error(*stack);
    new->data = data;
    new->next = NULL;
    tmp->next = new;
}

int check(t_stack *stack , int data)
{
    int i = 0;
    int j = 0;
    int size = stacksize(stack);
    int *arr = malloc(sizeof(int) * size);
    while (stack)
    {
        arr[i] = stack->data;
        stack = stack->next;
        i++;
    }
    while (j < size)
    {
        if (arr[j] == data){
            free(arr);
            return 0;}
        j++;
    }
    free(arr);
    return 1;
}

int control(char *str){
    int i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
            i++;
        else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
            i++;
        else if (str[i] == ' ')
            i++;
        else
            ft_error(NULL);
    }
    return 1;
}
int main(int ac, char **av)
{
    if (ac > 1){
        int j = 1;
        int i = 0;
        t_stack *stack_a = NULL;
        //t_stack *stack_b = NULL;
        char **str;
        if (ft_strlen(av[1]) == 0)
            ft_error(stack_a);
        while (av[j]){
            control(av[j]);
            j++;
        }
        j = 1;
        while (av[j] && ac > 1)
        {
            while (av[j]){
                if (av[j][i] != ' ')
                    i++;
                else{
                    i = 0;
                    str = ft_split(av[j], ' ');
                    if (!str)
                        ft_error(stack_a);
                    while (str[i])
                    {
                        if (check(stack_a, ft_atoi(str[i])) == 0)
                        {
                            free_tab(str);
                            ft_error(stack_a);
                        }
                        push(&stack_a, ft_atoi(str[i]));
                        i++;
                    }
                    free_tab(str);
                    ac--;
                    break;
                }
                if (av[j][i] == '\0'){
                    if (check(stack_a, ft_atoi(av[j])) == 0)
                        ft_error(stack_a);
                    push(&stack_a, ft_atoi(av[j]));
                    j++;
                    ac--;
                    i = 0;
                }
            }
            j++;
        }
        while (stack_a)
        {
            printf("%d\n", stack_a->data);
            stack_a = stack_a->next;
        }
        // free_stack(stack_b);
        //free_stack(stack_a);
    }
}