/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:27:55 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/05 23:43:41 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	while (a != NULL || b!= NULL)
	{
		if (a != NULL)
		{
			ft_putnbr_fd(a->value, 1);
			a = a->next;
		}
		ft_putchar_fd('\t', 1);
		if (b != NULL)
		{
			ft_putnbr_fd(b->value, 1);
			b = b->next;
		}
		ft_putchar_fd('\n', 1);
	}
	ft_putendl_fd("_\t_", 1);
	ft_putendl_fd("a\tb", 1);
}

int main (int argc, char *argv[])
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
	check_args(args);
	init_stack_a(&a,args);
	assign_index(a);
	if (!is_sorted(a))
    {
        if (stack_size(a) == 2)
            sort_2(&a);
        else if (stack_size(a) == 3)
            sort_3(&a);
		else if (stack_size(a) <= 5)
			sort_4_5(&a, &b);
		else
			turk_sort(&a, &b);
    }
	return (0);
}
