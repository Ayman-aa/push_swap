/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:05:02 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:05:02 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(t_stack **a, int param)
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
		if (!param)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack **b, int param)
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
		if (!param)
			write(1, "rb\n", 3);
	}
}

void	rotate_r(t_stack **a, t_stack **b, int param)
{
	rotate_a(a, param);
	rotate_b(b, param);
}
