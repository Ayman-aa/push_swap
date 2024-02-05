#include "includes/push_swap.h"

void    rotate_a(t_stacks *stack, int param)
{
    int tmp;
    int i;

    if(stack->size_a == 0 || stack->size_a == 1)
        return ;
    i = 0;
    tmp = stack->size_a[i];
    i++;
    while (i < stack->size_a)
    {
        stack->size_a[i - 1] = stack->size_a[i];
        i++;
    }
    stack->size_a[i - 1] = tmp;
    if (!param)
        write(1, "ra\n", 3);
}

void    rotate_b(t_stacks *stack, int param)
{
    int tmp;
    int i;

    if(stack->size_b == 0 || stack->size_b == 1)
        return ;
    i = 0;
    tmp = stack->size_b[i];
    i++;
    while (i < stack->size_b)
    {
        stack->size_b[i - 1] = stack->size_b[i];
        i++;
    }
    stack->size_b[i - 1] = tmp;
    if (!param)
        write(1, "rb\n", 3);
}

void    rotate_r(t_stacks *stack, int param)
{
    int	tmp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
		return ;
	i = 0;
	tmp = stack->a[i];
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = tmp;
	i = 0;
	tmp = stack->b[i];
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = tmp;
    if (!param)
        write(1, "rr\n", 3);
}