#include "../includes/push_swap.h"

void push_b(t_stacks *stack, int param)
{
    int i;

    if (stack->size_a)
    {
        stack->size_b++;
        i = stack->size_b;
        while (--i > 0)
            stack->size_b[i] = stack->size_b[i - 1];
        stack->size_b[0] = stack->size_a[0];
        i = -1;
        stack->size_a--;
        while (++i < stack->size_a)
            stack->size_a[i] = stack->size_a[i + 1];
        if (!param)
            write(1, "pb\n", 3);
    }
    else
        return ;
}

void push_a()
{}