/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:56:47 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 16:56:48 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*stack_top(t_stack *s)
{
	if (!s)
		return (NULL);
	return (s);
}

t_stack	*stack_bottom(t_stack *s)
{
	t_stack	*tmp;

	if (!s)
		return (NULL);
	tmp = s;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_stack	*stack_min(t_stack *s)
{
	t_stack	*min;

	if (!s)
		return (NULL);
	min = s;
	while (s)
	{
		if (s->value < min->value)
			min = s;
		s = s->prev;
	}
	return (min);
}

t_stack	*stack_max(t_stack *s)
{
	t_stack	*max;

	if (!s)
		return (NULL);
	max = s;
	while (s)
	{
		if (s->value > max->value)
			max = s;
		s = s->prev;
	}
	return (max);
}
