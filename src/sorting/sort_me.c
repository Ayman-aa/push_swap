/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:56:27 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/09 13:26:19 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	start_sort(t_stack **a, t_stack **b)
{
	(void)b;
	if (stack_size(*a) == 2)
		swap_a(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 4)
		sort_four(a, b);
	else if (stack_size(*a) == 5)
		sort_five(a, b);
	else if (stack_size(*a) >= 6)
	{
		sort_others(a, b, get_range(*a), stack_size(*a));
		while (*b)
		{
			max_to_top(b);
			push_a(a, b);
		}
	}
}

void	sort_three(t_stack **a)
{
	if (stack_top(*a)->value > stack_top(*a)->prev->value && \
	stack_top(*a)->prev->value < stack_bottom(*a)->value && \
	stack_top(*a)->value < stack_bottom(*a)->value)
		swap_a(a);
	else if (stack_top(*a)->value > stack_top(*a)->prev->value && \
	stack_top(*a)->prev->value > stack_bottom(*a)->value)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (stack_top(*a)->value > stack_top(*a)->prev->value && \
	stack_bottom(*a)->value > stack_top(*a)->prev->value)
		rotate_a(a);
	else if (stack_top(*a)->value < stack_top(*a)->prev->value && \
	stack_top(*a)->prev->value > stack_bottom(*a)->value && \
	stack_bottom(*a)->value > stack_top(*a)->value)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (stack_top(*a)->value < stack_top(*a)->prev->value && \
	stack_top(*a)->prev->value > stack_bottom(*a)->value && \
	stack_top(*a)->prev->value > stack_top(*a)->value)
		reverse_rotate_a(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (stack_min(*a) == stack_bottom(*a))
		reverse_rotate_a(a);
	else if (stack_min(*a) == stack_bottom(*a)->next)
	{
		reverse_rotate_a(a);
		reverse_rotate_a(a);
	}
	else if (stack_min(*a) == stack_top(*a)->prev)
		swap_a(a);
	if (!stack_sorted(*a, sorted))
	{
		push_b(a, b);
		sort_three(a);
		push_a(a, b);
	}
}

void	smallest_to_b(t_stack **a, t_stack **b)
{
	if (stack_min(*a) == stack_top(*a))
		push_b(a, b);
	else if (stack_min(*a) == stack_top(*a)->prev)
	{
		swap_a(a);
		push_b(a, b);
	}
	else if (stack_min(*a) == stack_bottom(*a)->next)
	{
		reverse_rotate_a(a);
		reverse_rotate_a(a);
		push_b(a, b);
	}
	else if (stack_min(*a) == stack_bottom(*a))
	{
		reverse_rotate_a(a);
		push_b(a, b);
	}
	else
	{
		rotate_a(a);
		rotate_a(a);
		push_b(a, b);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	smallest_to_b(a, b);
	smallest_to_b(a, b);
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
}
