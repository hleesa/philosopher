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

int	malloc_watcher_thread(t_wathcer **wathcer, int num_of_philo)
{
	*wathcer = malloc(sizeof(t_wathcer) * num_of_philo);
	if (*wathcer == NULL)
		return (-1);
	return (0);
}

int	init_watcher_thread(t_wathcer *wathcer, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->common_philo->number_of_philosophers)
	{
		wathcer->philo = philo;
	}
	return (0);
}


int create_watcher_thread(t_wathcer *wathcer, int num_of_watcher)
{
	int i;

	i = -1;
	while (++i < num_of_watcher)
	{
		if (pthread_create(&wathcer[i].tid, NULL, life_of_watcher,
						   (void *) (wathcer + i)) == -1)
			return (-1);
	}
	return (0);
}

int join_watcher_thread(t_wathcer *watcher, int num_fo_watcher)
{
	int	i;

	i = -1;
	while (++i < num_fo_watcher)
	{
		if (pthread_join(watcher[i].tid, NULL) == -1)
			return (-1);
	}
	return (0);
}

int create_watcher(t_wathcer *wathcer, t_philo *philo)
{
	if (malloc_watcher_thread(&wathcer, philo->common_philo->number_of_philosophers) == -1)
		return (-1);
	init_watcher_thread(wathcer, philo);
	if (create_watcher_thread(wathcer, philo->common_philo->number_of_philosophers) == -1)
		return (-1);
	if (join_watcher_thread(wathcer, philo->common_philo->number_of_philosophers) == -1)
		return (-1);
	return (0);
}
