#include "inlclude/push_swap.h"

void reverse_rotate_a(t_stacks *stack, int param)
{
    int tmp;
    int i;

    if (stack->size_a == 0 || stack->size_a == 1)
    return ;
i = stack->size_a -1;
tmp = stack->size_a[i];
while (i)
{
    stack->size_a[i] = stack-size_a[i - 1];
    i--;
}
stack-size_a[i] = tmp;
if (!param)
    write(1, "rra\n", 4);
}

void reverse_rotate_b(t_stacks *stack, int param)
{
    int tmp;
    int i;

    if (stack->size_b == 0 || stack->size_b == 1)
    return ;
i = stack->size_b - 1;
tmp = stack->size_b[i];
while (i)
{
stack->size_b[i] = stack->size_b[i - 1];
i--;
}
stack->size_b[i] = tmp;
if (!param)
write(1, "rrb\n", 4);
}