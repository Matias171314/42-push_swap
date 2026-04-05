/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:27:43 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/04 18:27:43 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (!stack || !stack->next)
		return ;
	tmp_value = stack->value;
	tmp_index = stack->index;
	stack->value = stack->next->value;
	stack->index = stack->next->index;
	stack->next->value = tmp_value;
	stack->next->index = tmp_index;
}

void	sa(t_stack **a)
{
	swap(*a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b)
{
	swap(*b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_putendl_fd("ss", 1);
}
