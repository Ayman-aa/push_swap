/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:43:29 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:43:29 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack **a)
{
	if (stack_size(*a) >= 2)
		swap(&(*a)->value, &(*a)->prev->value);
}

void	sb(t_stack **b)
{
	if (stack_size(*b) >= 2)
		swap(&(*b)->value, &(*b)->prev->value);
}

void	ss(t_stack **a, t_stack **b)
{
	if (stack_size(*a) >= 2)
		swap(&(*a)->value, &(*a)->prev->value);
	if (stack_size(*b) >= 2)
		swap(&(*b)->value, &(*b)->prev->value);
}
