/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:46:31 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/02 10:01:53 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_atoi(char *str, int *stack)
{
    unsigned int    i;
    int             sign;
    unsigned int    result;

    i = 0;
    result = 0;
    sign = 1;
    while ((str[i] >= '9' && str[i] <= '13') || str[i] == ' ')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] < '0' && str[i] > '9')
            ft_error(stack);
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if ((result > 2147483647 && sign == 1) 
    || (result > 2147483648 && sign == -1))
        ft_error(stack);
    return (result * sign);
}

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}