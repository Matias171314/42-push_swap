/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:27:55 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/09 18:37:03 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	choose_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_4_5(a, b);
	else
		turk_sort(a, b);
}

int	main(int argc, char *argv[])
{
	char	**args;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && !argv[1][0])
		ft_error("Error");
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	check_args(args, argc == 2);
	init_stack_a(&a, args);
	if (argc == 2)
		free_split(args);
	assign_index(a);
	if (!is_sorted(a))
		choose_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
