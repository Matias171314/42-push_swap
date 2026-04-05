/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 23:00:51 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/05 23:00:51 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_lowest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		target_idx;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	while (tmp_b)
	{
		target_idx = INT_MAX;
		tmp_a = *a;
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index && tmp_a->index < target_idx)
			{
				target_idx = tmp_a->index;
				tmp_b->target_pos = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
		if (target_idx == INT_MAX)
			tmp_b->target_pos = get_lowest_index_pos(a);
		tmp_b = tmp_b->next;
	}
}
