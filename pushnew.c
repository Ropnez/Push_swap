#include <stdlib.h>
#include "push_swap.h"

void push_str(t_stack **stack, char *str)
{
    int i = 0;
    char **tab = ft_split(str, ' ');
    if (!tab)
        ft_error(*stack);
    while (tab[i])
    {
        if (check(*stack, ft_atoi(tab[i])) == 0)
        {
            free_tab(tab);
            ft_error(*stack);
        }
        push_init(stack, ft_atoi(tab[i]));
        i++;
    }
    free_tab(tab);
}

void ft_control(t_stack *stack_a, char **av, int j)
{
    if (ft_strlen(av[1]) == 0)
        ft_error(stack_a);
    while (av[j]){
        control(av[j]);
        j++;
    }
}

void push_norm(t_stack **stack, char *str)
{
    if (check(*stack, ft_atoi(str)) == 0)
        ft_error(*stack);
    push_init(stack, ft_atoi(str));

}

void ft_while(t_stack **stack_a, char **av, int j, int ac)
{
    int i = 0;
    while (av[j] && ac > 1)
    {
        while (av[j])
        {
            if (av[j][i] != ' ')
                i++;
            else
            {
                push_str(stack_a, av[j]);
                ac--;
                break;
            }
            if (av[j][i] == '\0')
            {
                push_norm(stack_a, av[j]);
                j++;
                ac--;
                i = 0;
            }
        }
        j++;
    }
}

int main(int ac, char **av)
{
    if (ac > 1){
        int j = 1;
        int i = 0;
        t_stack *stack_a = NULL;
        t_stack *stack_b = NULL;
        ft_control(stack_a, av, j);
        ft_while(&stack_a, av, j, ac);
    }
    return 0;
}
