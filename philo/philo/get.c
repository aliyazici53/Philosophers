/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:30:41 by alyazici          #+#    #+#             */
/*   Updated: 2022/10/16 16:55:51 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_death_value(t_table *table)
{
	int	value;

	pthread_mutex_lock(&table->death_check);
	value = table->death;
	pthread_mutex_unlock(&table->death_check);
	return (value);
}

t_state	get_state(t_philo *philo)
{
	t_state	value;

	pthread_mutex_lock(philo->state_check);
	value = philo->state;
	pthread_mutex_unlock(philo->state_check);
	return (value);
}

size_t	get_last_meal(t_philo *philo)
{
	size_t	value;

	pthread_mutex_lock(philo->last_eat_check);
	value = philo->last_eat;
	pthread_mutex_unlock(philo->last_eat_check);
	return (value);
}

int	get_n_eat(t_philo *philo)
{
	int	value;

	pthread_mutex_lock(philo->n_eat_check);
	value = philo->n_eat;
	pthread_mutex_unlock(philo->n_eat_check);
	return (value);
}
