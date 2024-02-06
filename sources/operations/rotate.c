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

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*to_bottom;
	int		data;

	if (stack_size(*a) >= 2)
	{
		data = pop(a);
		to_bottom = create_node(data);
		tmp = stack_bottom(*a);
		to_bottom->next = tmp;
		tmp->prev = to_bottom;
		write(1, "ra\n", 3);
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
		to_bottom = create_node(data);
		tmp = stack_bottom(*b);
		to_bottom->next = tmp;
		tmp->prev = to_bottom;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}