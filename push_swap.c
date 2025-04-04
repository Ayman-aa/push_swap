/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:58:57 by aaamam            #+#    #+#             */
/*   Updated: 2024/03/01 21:17:57 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		arr_num;
	char	**arr;

	b = NULL;
	a = NULL;
	arr = _parsed_arr(_parsed_av(ac, av));
	arr_num = arr_n(arr, av);
	fill_stack(&a, arr_num, arr);
	if (arr_num == 2 && a->data > a->next->data)
		sa(a, 0);
	else if (arr_num == 3)
		sort_three(&a);
	else if (arr_num == 4)
		sort_four(&a, &b);
	else if (arr_num == 5)
		sort_five(&a, &b);
	else
	{
		quick_divide_qs(&a, &b, find_interval(&a), stack_size(&a));
		while (b)
			move_max_up(&a, &b);
	}
	// print_stack(a);
	free_all(a, arr);
}
