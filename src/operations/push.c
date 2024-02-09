/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:07:37 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:07:37 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	if (stack_size(*b))
	{
		push(a, pop(b));
		write(1, "pa\n", 3);
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	if (stack_size(*a))
	{
		push(b, pop(a));
		write(1, "pb\n", 3);
	}
}