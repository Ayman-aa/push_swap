/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:46:29 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/08 17:46:29 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(char *str)
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

int	ft_duplicate(t_stack *a, long long n)
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

void	initialize_stack(t_stack **a, int ac, char **av)
{
	int		j;
	char	**splited;

	while (ac >= 0)
	{
		splited = ft_split(av[ac], ' ');
		if (splited == NULL)
		{
			free(splited);
			ft_error();
		}
		j = 0;
		while (splited[j + 1])
			j++;
		while (j >= 0)
		{
			if (is_number(splited[j]) || ft_duplicate(*a, ft_atol(splited[j])))
				ft_error();
			push(a, ft_atol(splited[j]));
			j--;
		}
		j = 0;
		free_all(splited);
		ac--;
	}
}