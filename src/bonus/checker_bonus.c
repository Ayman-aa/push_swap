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

#include "push_swap_bonus.h"

void	apply_operations(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		_sa(a);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		_sb(b);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		_ss(a, b);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		_pa(a, b);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		_pb(a, b);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		_ra(a);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		_rb(b);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		_rr(a, b);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		_rra(a);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		_rrb(b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		_rrr(a, b);
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
