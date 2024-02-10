/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:57:36 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/06 17:59:58 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	apply_operations(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		swap_a(a, 1);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		swap_b(b, 1);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		swap_s(a, b, 1);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		push_a(a, b, 1);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		push_b(a, b, 1);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		rotate_a(a, 1);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rotate_b(b, 1);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rotate_r(a, b, 1);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		reverse_rotate_a(a, 1);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		reverse_rotate_b(b, 1);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		reverse_rotate_r(a, b, 1);
	else
		ft_error();
}

void	start_cheking(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_operations(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else
		initialize_stack(&a, ac - 2, av + 1);
	if (stack_sorted(a, sorted) == 0)
	{
		start_cheking(&a, &b);
		if (stack_sorted(a, sorted) == 1 && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "OK\n", 3);
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}
