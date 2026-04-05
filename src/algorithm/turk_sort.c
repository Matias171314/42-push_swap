/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 23:17:36 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/05 23:17:36 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	shift_stack(t_stack **a)
{
	int	lowest_pos;
	int	size;

	size = stack_size(*a);
	lowest_pos = get_lowest_index_pos(a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(a);
			lowest_pos--;
		}
	}
}

static void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < cheapest)
		{
			cheapest = abs(tmp->cost_a) + abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}

static void	push_all_save_three(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	push_all_save_three(a, b);
	sort_3(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
