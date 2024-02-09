/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:56:21 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 16:56:22 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	insertion_sort(int *arr, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(&arr[i], &arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int	*stack_to_sarray(t_stack *s)
{
	int		*arr;
	t_stack	*tmp;
	int		i;
	int		size;

	i = 0;
	if (!s)
		return (NULL);
	tmp = s;
	size = stack_size(s);
	arr = malloc(size * sizeof(int));
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->prev;
	}
	insertion_sort(arr, size);
	return (arr);
}
