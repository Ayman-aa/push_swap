/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:42:38 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:42:38 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **a)
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
	}
}

void	rrb(t_stack **b)
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
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
