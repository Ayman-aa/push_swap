/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:56:36 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 18:02:00 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create_node(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = n;
	new->next = NULL;
	new->prev = NULL;
	return (new);
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

int	stack_size(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	if (!tmp)
		return (0);
	return (1 + stack_size(tmp->prev));
}

