/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:53:09 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 16:53:09 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_stack(t_stack **a, int ac, char **av)
{
	int		j;
	char	**sp;

	while (ac >= 0)
	{
		sp = ft_split(av[ac], ' ');
		if (sp == NULL)
		{
			free(sp);
			ft_error();
		}
		j = 0;
		while (sp[j + 1])
			j++;
		while (j >= 0)
		{
			if (is_number(sp[j]) || ft_duplicate(*a, ft_atol(sp[j])))
				ft_error();
			push(a, ft_atol(sp[j]));
			j--;
		}
		j = 0;
		free_all(sp);
		ac--;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else
		initialize_stack(&a, ac - 2, av + 1);
	if (stack_sorted(a, sorted) == 0)
		start_sort(&a, &b);
	free_stack(&a);
	return (0);
}
