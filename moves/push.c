/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:37 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/28 16:05:26 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

void	pa(t_stack **a, t_stack **b, int param)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = (*a);
		(*a) = (*b);
		(*b) = tmp;
		if (!param)
			write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b, int param)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	if (*a)
	{
		tmp = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = tmp;
		if (!param)
			write(1, "pb\n", 3);
	}
}
