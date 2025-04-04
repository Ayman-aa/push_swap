/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:36 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/28 16:05:25 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_stack **ab, t_stack *new)
{
	if (!ab || !new)
		return ;
	new->next = *ab;
	*ab = new;
}

void	rra(t_stack **a, int param)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*prev;

	if (!(*a) || !(*a)->next)
		return ;
	current = *a;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	last = current;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (!param)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int param)
{
	t_stack	*last;
	t_stack	*current;

	current = *b;
	if (!(*b) || !(*b)->next)
		return ;
	while (current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *b;
	*b = last;
	if (!param)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int param)
{
	rra(a, 1);
	rrb(b, 1);
	if (!param)
		write(1, "rrr\n", 4);
}
