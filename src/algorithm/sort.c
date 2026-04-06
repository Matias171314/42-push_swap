/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:14:07 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/06 15:39:51 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && top > bot)
		ra(a);
	else if (mid > top && mid > bot)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static int	get_min_pos(t_stack *a)
{
	int		min_index;
	int		min_pos;
	int		current_pos;
	t_stack	*tmp;

	tmp = a;
	min_index = tmp->index;
	min_pos = 0;
	current_pos = 0;
	while (tmp != NULL)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = current_pos;
		}
		current_pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack **a)
{
	int	min_pos;
	int	size;

	min_pos = get_min_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
}

void	sort_4_5(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	while (stack_size(*a) > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_3(a);
	while (*b != NULL)
		pa(a, b);
}
