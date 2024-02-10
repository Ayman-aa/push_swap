/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_to_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:56:31 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/10 09:59:08 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_range(t_stack *a)
{
	int	range;

	range = 0;
	if (stack_size(a) >= 6 && stack_size(a) <= 16)
		range = 3;
	else if (stack_size(a) <= 100)
		range = 13;
	else if (stack_size(a) <= 500)
		range = 35;
	else
		range = 45;
	return (range);
}

static void	push_rotate_b(t_stack **a, t_stack **b, int *i)
{
	push_b(a, b, 0);
	rotate_b(b, 0);
	(*i)++;
}

void	sort_others(t_stack **a, t_stack **b, int range, int size)
{
	int	*sarr;
	int	i;

	sarr = stack_to_sarray(*a);
	i = 0;
	while (*a)
	{
		if (range + i >= size)
			range = size - i - 1;
		if (stack_top(*a)->value <= sarr[i])
			push_rotate_b(a, b, &i);
		else if ((*a)->value > sarr[i] && (*a)->value <= sarr[range + i])
		{
			push_b(a, b, 0);
			if (stack_size(*b) >= 2 && (*b)->value < (*b)->prev->value)
				swap_b(b, 0);
			i++;
		}
		else
			rotate_a(a, 0);
	}
	free(sarr);
}

int	max_index(t_stack *b)
{
	int	index;

	index = 0;
	while (b && stack_max(b) != b)
	{
		b = b->prev;
		index++;
	}
	return (index);
}

void	max_to_top(t_stack **b)
{
	int	index;
	int	size;

	size = stack_size(*b);
	while (1)
	{
		index = max_index(*b);
		if (index == 0)
			break ;
		else if (index <= size / 2)
			rotate_b(b, 0);
		else if (index > size / 2)
			reverse_rotate_b(b, 0);
	}
}
