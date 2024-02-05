#include "includes/push_swap.h"

void    swap_a(t_stacks *stack, int param)
{
    int tmp;

    if (stack->size_a == 0 || stack->size_a == 1)
        return ;
    tmp = 0;
    tmp = stack->size_a[0];
    stack->size_a[0] = stack->size_a[1];
    stack->size_a[1] = tmp;
    if (!param)
        write(1, "sa\n", 3);
}

void    swap_b(t_stacks *stack, int param)
{
    int tmp;

    if (stack->size_b == 0 || stack->size_b == 1)
        return ;
    tmp = 0;
    tmp = stack->size_b[0];
    stack->size_b[0] = stack->size_b[1];
    stack->size_b[1] = tmp;
    if (!param)
        write(1, "sb\n", 3);
}

void    swap_s(t_stacks *stack, int param)
{
    int tmp;

    if (stack->size_a == 0 || stack->size_a == 1
        || stack->size_b == 0 || stack->size_b == 1)
        return ;
    tmp = 0;
    tmp = stack->size_a[0];
    stack->size_a[0] = stack->size_a[1];
    stack->size_a[1] = tmp;
    tmp = stack->size_b[0];
    stack->size_b[0] = stack->size_b[1];
    stack->size_b[1] = tmp;
    if (!param)
        write(1, "ss\n", 3);
}