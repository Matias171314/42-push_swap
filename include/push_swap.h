/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:17:30 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/09 18:33:11 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

void	ft_error(char *msg);
int		is_valid_number(char *str);
int		has_duplicates(char **args);
void	free_split(char **split);
void	check_args(char **args, int is_split);

long	ft_atol(const char *str);
int		ft_abs(int n);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);

t_stack	*new_stack_node(int value);
void	stack_node_add_back(t_stack **stack, t_stack *new_node);
void	init_stack_a(t_stack **a, char **args);
void	assign_index(t_stack *a);
int		stack_size(t_stack *stack);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	sort_4_5(t_stack **a, t_stack **b);

void	get_position(t_stack **stack);
int		get_lowest_index_pos(t_stack **stack);
void	get_target_position(t_stack **a, t_stack **b);
void	get_cost(t_stack **a, t_stack **b);

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void	turk_sort(t_stack **a, t_stack **b);

#endif