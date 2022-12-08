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

int	malloc_watcher_thread(t_watcher **wathcer, t_common_philo *common_philo)
{
	*wathcer = malloc(sizeof(t_watcher) * common_philo->number_of_philosophers);
	if (*wathcer == NULL)
	{
		return (-1);
	}
	return (0);
}

int	init_watcher_thread(t_watcher *wathcer, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].common_philo->number_of_philosophers)
	{
		wathcer[i].philo = &philo[i];
		wathcer[i].time_to_die = philo[i].common_philo->time_to_die;
	}
	return (0);
}


int create_watcher_thread(t_watcher *wathcer, t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo[0].common_philo->number_of_philosophers)
	{
		if (pthread_create(&wathcer[i].tid, NULL, life_of_watcher,
						   (void *) (wathcer + i)) == -1)
			return (-1);
	}
	return (0);
}

int join_watcher_thread(t_watcher *watcher,t_common_philo *common_philo)
{
	int	i;

	i = -1;
	while (++i < common_philo->number_of_philosophers)
	{
		if (pthread_join(watcher[i].tid, NULL) == -1)
			return (-1);
	}
	return (0);
}
/*
int create_watcher(t_watcher *wathcer, t_philo *philo, t_common_philo *common_philo)
{
	if (malloc_watcher_thread(&wathcer, common_philo) == -1)
		return (-1);
	init_watcher_thread(wathcer, philo);
	if (create_watcher_thread(wathcer, philo) == -1)
		return (-1);
	if (join_watcher_thread(wathcer, philo) == -1)
		return (-1);
	return (0);
}
*/