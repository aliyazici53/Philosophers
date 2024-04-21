/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:30:35 by alyazici          #+#    #+#             */
/*   Updated: 2022/10/16 16:54:28 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(const char *str)
{
	int		nbr;
	size_t	digits;
	size_t	i;

	i = 0;
	nbr = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		digits++;
		if ((nbr * 10 + (str[i] - '0')) / 10 != nbr)
			return (0);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (!str[i] && digits);
}

int	check_negative(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5)
		return (print_error("parser", "too few arguments", 0));
	if (argc > 6)
		return (print_error("parser", "too much arguments", 0));
	i = 0;
	while (++i < argc)
	{
		if (!check_int(argv[i]))
			return (print_error("parser", "argument should be numeric.", 0));
		if (!check_negative(argv[i]))
			return (print_error("parser", "argument should be positive.", 0));
		if (!ft_atoi(argv[i]))
			return (print_error("parser",
					"argument should be greater than zero.", 0));
	}
	return (1);
}
