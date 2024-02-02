/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:36:56 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/02 09:45:56 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_error(int *stack)
{
	free(stack);
	write(1, "Error\n", 6);
	exit (1);
}

int ft_isorted(int *stack, int size, int order)
{
    int i;

    i = 0;
    if (order == 0)
    {
        i = 1;
        while (i < size)
        {
            if (stack[i - 1] > stack[i])
                return (0);
            i++;
        }
        return (1);
    }
    else
    {
        i = 1;
        while (i < size)
        {
            if (stack[i - 1] < stack[i])
                return (0);
            i++;
        }
        return (1);
    }
}

void    ft_isrepeated(int *stack, int size)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < size)
    {
        while (j < size)
        {
            if (stack[i] == stack[j])
                ft_error(stack);
            j++;
        }
        i++;
        j = i + 1;
    }
}