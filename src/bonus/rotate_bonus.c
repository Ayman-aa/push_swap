/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:42:52 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:42:52 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*to_bottom;
	int		data;

	if (stack_size(*a) >= 2)
	{
		data = pop(a);
		to_bottom = new_node(data);
		tmp = stack_bottom(*a);
		to_bottom->next = tmp;
		tmp->prev = to_bottom;
	}
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*to_bottom;
	int		data;

	if (stack_size(*b) >= 2)
	{
		data = pop(b);
		to_bottom = new_node(data);
		tmp = stack_bottom(*b);
		to_bottom->next = tmp;
		tmp->prev = to_bottom;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
