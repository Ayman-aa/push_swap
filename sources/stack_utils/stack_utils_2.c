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
