/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:31:01 by alyazici          #+#    #+#             */
/*   Updated: 2022/10/16 16:57:29 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*parse_args(int argc, char **argv)
{
	t_table	*table;

	if (!check_args(argc, argv))
		return (NULL);
	table = (t_table *) malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc - 1 == 5)
		table->min_to_eat = ft_atoi(argv[5]);
	else
		table->min_to_eat = -1;
	table->death = 0;
	table->philo = malloc(sizeof(t_philo) * (table->count + 1));
	table->forks = malloc(sizeof(pthread_mutex_t) * (table->count + 1));
	table->time = time_get_now();
	pthread_mutex_init(&table->is_diying, NULL);
	pthread_mutex_init(&table->is_printing, NULL);
	pthread_mutex_init(&table->death_check, NULL);
	return (table);
}
