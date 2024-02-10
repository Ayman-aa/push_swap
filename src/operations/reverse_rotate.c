/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:05:30 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:05:30 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_a(t_stack **a, int param)
{
	t_stack	*bottom;

	if (stack_size(*a) >= 2)
	{
		bottom = stack_bottom(*a);
		bottom->next->prev = NULL;
		(*a)->next = bottom;
		bottom->prev = *a;
		*a = (*a)->next;
		(*a)->next = NULL;
		if (!param)
			write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_stack **b, int param)
{
	t_stack	*bottom;

	if (stack_size(*b) >= 2)
	{
		bottom = stack_bottom(*b);
		bottom->next->prev = NULL;
		(*b)->next = bottom;
		bottom->prev = *b;
		*b = (*b)->next;
		(*b)->next = NULL;
		if (!param)
			write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_r(t_stack **a, t_stack **b, int param)
{
	reverse_rotate_a(a, param);
	reverse_rotate_b(b, param);
}
