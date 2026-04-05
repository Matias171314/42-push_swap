/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:47:53 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/03 21:47:53 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (*str == '\0')
        return (0);
    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int	has_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_args (char **args)
{
	long	num;
	int		i;

	if (has_duplicates(args))
		ft_error("Error");
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
			ft_error("Error");
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error("Error");
		i++;
	}
}
