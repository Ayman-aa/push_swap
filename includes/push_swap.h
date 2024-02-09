/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:28:41 by aaamam            #+#    #+#             */
/*   Updated: 2024/02/02 09:33:28 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stacks
{
	int				value;
	struct s_stacks	*next;
	struct s_stacks	*prev;
}					t_stack;

void				initialize_stack(t_stack **a, int ac, char **av);

// instructions
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				swap_s(t_stack **a, t_stack **b);
void				rotate_a(t_stack **a);
void				rotate_b(t_stack **b);
void				rotate_r(t_stack **a, t_stack **b);
void				reverse_rotate_a(t_stack **a);
void				reverse_rotate_b(t_stack **b);
void				reverse_rotate_r(t_stack **b, t_stack **a);

// parsing
void				ft_error(void);
int					ft_isdigit(int c);
int					is_number(char *str);
int					ft_duplicate(t_stack *a, long long n);

// stack tools
int					sorted(int a, int b);
void				swap(int *a, int *b);
void				push(t_stack **s, int n);
int					pop(t_stack **s);
long long			ft_atol(const char *str);

// stack indexing
t_stack				*stack_bottom(t_stack *s);
t_stack				*stack_top(t_stack *s);
t_stack				*stack_min(t_stack *s);
t_stack				*stack_max(t_stack *s);

// stack behavior
t_stack				*new_node(int n);
int					stack_size(t_stack *s);
int					stack_sorted(t_stack *s, int (*sorted)(int, int));
void				free_stack(t_stack **s);
void				*free_all(char **seperated);

// sorting
void				start_sort(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				sort_others(t_stack **a, t_stack **b, int range, int size);
void				smallest_to_b(t_stack **a, t_stack **b);

// sorting utils
int					*stack_to_sarray(t_stack *s);
int					get_range(t_stack *s);
int					max_index(t_stack *b);
void				max_to_top(t_stack **b);
static void			push_rotate_b(t_stack **a, t_stack **b, int *i);

#endif