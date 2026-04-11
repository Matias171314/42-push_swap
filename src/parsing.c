/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:47:53 by mvasquez          #+#    #+#             */
/*   Updated: 2026/04/09 18:34:34 by mvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

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

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	check_args(char **args, int is_split)
{
	int		i;

	if (has_duplicates(args))
	{
		if (is_split)
			free_split(args);
		ft_error("Error");
	}
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
		{
			if (is_split)
				free_split(args);
			ft_error("Error");
		}
		if (ft_atol(args[i]) < INT_MIN || ft_atol(args[i]) > INT_MAX)
		{
			if (is_split)
				free_split(args);
			ft_error("Error");
		}
		i++;
	}
}
