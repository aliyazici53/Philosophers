/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:31:33 by alyazici          #+#    #+#             */
/*   Updated: 2022/10/16 16:57:48 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_start(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->count)
		philo_init(table->philo + i, table, i);
	i = -1;
	while (++i < table->count)
		philo_forks_init(table->philo + i, table, i);
	i = -1;
	while (++i < table->count)
		pthread_create(&table->philo[i].thread, NULL, \
				philo_routine, table->philo + i);
	i = -1;
	philo_check_death(table);
	while (++i < table->count && table->count != 1)
		pthread_join(table->philo[i].thread, NULL);
}

void	threads_wait(t_table *table)
{
	int	i;

	time_usleep(100);
	i = -1;
	while (++i < table->count)
		pthread_mutex_destroy(table->forks + i);
	pthread_mutex_destroy(&table->is_printing);
	pthread_mutex_destroy(&table->is_diying);
	pthread_mutex_destroy(&table->death_check);
	i = -1;
	while (++i < table->count)
	{
		free((table->philo + i)->last_eat_check);
		free((table->philo + i)->n_eat_check);
		free((table->philo + i)->state_check);
	}
	free(table->philo);
	free(table->forks);
	free(table);
}
