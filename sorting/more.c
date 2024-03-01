/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:27 by aaamam            #+#    #+#             */
/*   Updated: 2024/03/01 21:17:04 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_interval(t_stack **a)
{
	int	interval;

	interval = 0;
	if (stack_size(a) >= 6 && stack_size(a) <= 16)
		interval = 3;
	else if (stack_size(a) <= 100)
		interval = 13;
	else if (stack_size(a) <= 500)
		interval = 30;
	else
		interval = 45;
	return (interval);
}

void	pb_rb(t_stack **a, t_stack **b, int *i)
{
	pb(a, b, 0);
	rb(b, 0);
	(*i)++;
}

void	quick_divide_qs(t_stack **a, t_stack **b, int interval, int size)
{
	int	i;
	int	*s_arr;

	i = 0;
	s_arr = sorted_stack_array(a);
	if (max_to_min(a) == 0)
	{
		while (i < size)
		{
			ra(a, 0);
			i++;
		}
		if (sorted(a))
			return ;
	}
	while (*a)
	{
		if (interval + i >= size)
			interval = size - i - 1;
		if (stack_head(a)->data <= s_arr[i])
			pb_rb(a, b, &i);
		else if ((*a)->data > s_arr[i] && (*a)->data <= s_arr[i + interval])
		{
			pb(a, b, 0);
			if (stack_size(b) >= 2 && (*b)->data < (*b)->next->data)
				sb(*b, 0);
			i++;
		}
		else if (max_to_min(a) == 0)
			rra(a, 0);
		else
			ra(a, 0);
	}
	free(s_arr);
}

void	move_max_up(t_stack **a, t_stack **b)
{
	int	size;
	int	peak;

	size = stack_size(b);
	peak = 0;
	while (1)
	{
		peak = peak_index(b, stack_biggest(b));
		if (peak == 0)
			break ;
		else if (peak <= size / 2)
			rb(b, 0);
		else if (peak > size / 2)
			rrb(b, 0);
	}
	pa(a, b, 0);
}

int	max_to_min(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a)
		return (0);
	tmp = *a;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}
