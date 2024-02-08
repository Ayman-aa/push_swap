/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:56:41 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 16:56:42 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sorted(int a, int b)
{
	return (a < b);
}

int	stack_sorted(t_stack *s, int (*sorted)(int, int))
{
	t_stack	*tmp;

	tmp = s;
	while (tmp->prev)
	{
		if (sorted(tmp->value, tmp->prev->value) == 0)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
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

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	push(t_stack **s, int n)
{
	t_stack	*new;

	new = create_node(n);
	if (s)
	{
		if (*s)
		{
			(*s)->next = new;
			new->prev = *s;
		}
		*s = new;
	}
}

int	pop(t_stack **s)
{
	int		popped;
	t_stack	*tmp;

	if (!*s)
		return (0);
	tmp = *s;
	*s = (*s)->prev;
	if (*s)
		(*s)->next = NULL;
	popped = tmp->value;
	free(tmp);
	return (popped);
}

