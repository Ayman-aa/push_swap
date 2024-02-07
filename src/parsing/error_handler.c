/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:56:10 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 18:00:14 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	error_generator(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	av_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || ft_isdigit(str[i])))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[++i]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	dup_error(t_stack *a, long long n)
{
	t_stack	*tmp;

	tmp = a;
	if (n > 2147483647 || n < -2147483648)
		return (1);
	if (!a)
		return (0);
	while (tmp)
	{
		if (tmp->value == n)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}
