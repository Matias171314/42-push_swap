/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:51:32 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/04 12:51:32 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*new_stack_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	stack_node_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

void	init_stack_a(t_stack **a, char **args)
{
	int		n;
	int		i;
	t_stack *new_node;

	i = 0;
	while (args[i])
	{
		n = ft_atoi(args[i]);
		new_node = new_stack_node(n);
		if (!new_node)
			return;
		stack_node_add_back(a, new_node);
		i++;
	}
}

void	assign_index(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;

	current = a;
	while (current != NULL)
	{
		count = 0;
		compare = a;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
