/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:03:22 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:03:22 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stack **a)
{
	if (stack_size(*a) >= 2)
	{
		swap(&(*a)->value, &(*a)->prev->value);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack **b)
{
	if (stack_size(*b) >= 2)
	{
		swap(&(*b)->value, &(*b)->prev->value);
		write(1, "sb\n", 3);
	}
}

void	swap_s(t_stack **a, t_stack **b)
{
	if (stack_size(*a) >= 2)
		swap(&(*a)->value, &(*a)->prev->value);
	if (stack_size(*b) >= 2)
		swap(&(*b)->value, &(*b)->prev->value);
	write(1, "ss\n", 3);
}