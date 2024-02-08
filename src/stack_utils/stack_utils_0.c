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

t_stack	*new_node(int n)
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

int	stack_size(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	if (!tmp)
		return (0);
	return (1 + stack_size(tmp->prev));
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

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!*s)
		return ;
	tmp = *s;
	while (tmp)
	{
		tmp = (*s)->prev;
		free(*s);
		*s = tmp;
	}
}
