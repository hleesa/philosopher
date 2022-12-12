/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:39:19 by salee2            #+#    #+#             */
/*   Updated: 2022/12/07 18:39:19 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_watcher_thread(t_watcher **wathcer)
{
	*wathcer = malloc(sizeof(t_watcher));
	if (*wathcer == NULL)
		return (-1);
	return (0);
}

int	init_watcher_thread(t_watcher *wathcer, t_philo *philo)
{
	int			i;
	const int	i_end = philo->common_philo->number_of_philosophers;

	wathcer->philo = malloc(sizeof(*philo) * i_end);
	wathcer->time_to_die = philo->common_philo->time_to_die;
	i = -1;
	while (++i < i_end)
		wathcer->philo[i] = philo[i];
	return (0);
}

int create_watcher_thread(t_watcher *wathcer)
{
	if (pthread_create(&wathcer->tid, NULL, life_of_watcher, (void *) (wathcer)) == -1)
			return (-1);
	return (0);
}

int join_watcher_thread(t_watcher *watcher)
{
	if (pthread_join(watcher->tid, NULL) == -1)
			return (-1);
	return (0);
}
