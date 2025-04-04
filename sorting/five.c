/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:28 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/28 16:05:17 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = stack_smallest(a);
	if (min->data == (*a)->next->data)
	{
		sa(*a, 0);
		pb(a, b, 0);
	}
	else if (min->data == (*a)->next->next->data)
	{
		ra(a, 0);
		ra(a, 0);
		pb(a, b, 0);
	}
	else if (min->data == (*a)->next->next->next->data)
	{
		rra(a, 0);
		rra(a, 0);
		pb(a, b, 0);
	}
	else if (min->data == (*a)->next->next->next->next->data)
	{
		rra(a, 0);
		pb(a, b, 0);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = stack_smallest(a);
	if (min->data == (*a)->data)
		pb(a, b, 0);
	else if (min->data == (*a)->next->data)
	{
		sa(*a, 0);
		pb(a, b, 0);
	}
	else if (min->data == (*a)->next->next->data)
	{
		ra(a, 0);
		ra(a, 0);
		pb(a, b, 0);
	}
	else if (min->data == (*a)->next->next->next->data)
	{
		rra(a, 0);
		pb(a, b, 0);
	}
	sort_three(a);
	pa(a, b, 0);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = stack_smallest(a);
	if (min->data == (*a)->data)
		pb(a, b, 0);
	else
		min_to_b(a, b);
	sort_four(a, b);
	pa(a, b, 0);
}
