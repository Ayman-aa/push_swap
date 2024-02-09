/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:42:20 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:42:20 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a_bonus(t_stack **a, t_stack **b)
{
	if (stack_size(*b))
		push(a, pop(b));
}

void	push_b_bonus(t_stack **a, t_stack **b)
{
	if (stack_size(*a))
		push(b, pop(a));
}