/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:22:31 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/08 18:22:31 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sorted(int a, int b)
{
	return (a < b);
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

	new = new_node(n);
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

long long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
