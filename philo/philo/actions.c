/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:30:21 by alyazici          #+#    #+#             */
/*   Updated: 2022/10/16 16:30:25 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_use_fork(t_philo *philo,
			int (*mutex_action)(pthread_mutex_t *), char *message)
{
	set_state(philo, TAKING);
	mutex_action(philo->lfork);
	print(philo, message);
	mutex_action(philo->rfork);
	print(philo, message);
	set_state(philo, INITIAL);
}

void	philo_eat(t_philo *philo)
{
	philo_use_fork(philo, pthread_mutex_lock, HAS_TAKEN_A_FORK);
	set_last_meal(philo, time_get_millis_now());
	print(philo, IS_EATING);
	set_state(philo, EATING);
	time_usleep(philo->table->time_to_eat);
	set_state(philo, INITIAL);
	philo->n_eat++;
	philo_use_fork(philo, pthread_mutex_unlock, NULL);
}

void	philo_sleep(t_philo *philo)
{
	print(philo, IS_SLEEPING);
	set_state(philo, SLEEPING);
	time_usleep(philo->table->time_to_sleep);
	set_state(philo, INITIAL);
}

void	philo_think(t_philo *philo)
{
	set_state(philo, THINKING);
	print(philo, IS_THINKING);
	set_state(philo, INITIAL);
}
