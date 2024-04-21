/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:30:02 by alyazici          #+#    #+#             */
/*   Updated: 2022/10/16 16:32:31 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	time_get_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}

size_t	time_get_millis(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	time_get_millis_now(void)
{
	return (time_get_millis(time_get_now()));
}

size_t	time_get_millis_from_start(t_table *table)
{
	return (time_get_millis_now() - time_get_millis(table->time));
}

void	time_usleep(size_t	usec)
{
	size_t	current;

	current = time_get_millis_now();
	while (usec > time_get_millis_now() - current)
		usleep(usec * 10);
}
