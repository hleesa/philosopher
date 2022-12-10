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

int	malloc_watcher_thread(t_watcher **wathcer, int size)
{
	*wathcer = malloc(sizeof(t_watcher) * size);
	if (*wathcer == NULL)
		return (-1);
	return (0);
}

int	init_watcher_thread(t_watcher *wathcer, t_philo *philo, t_common_watcher *common_watcher)
{
	int			i;
	const int	i_end = philo->common_philo->number_of_philosophers;
	const ll	time_to_die = philo[0].common_philo->time_to_die;

	i = -1;
	while (++i < i_end)
	{
		wathcer[i].philo = &philo[i];
		wathcer[i].time_to_die = time_to_die;
		wathcer[i].common_watcher = common_watcher;
	}
	return (0);
}

int create_watcher_thread(t_watcher *wathcer, int i_end)
{
	int	i;

	pthread_mutex_t start_mtx;
	pthread_mutex_init(&start_mtx, NULL);
	pthread_mutex_lock(&start_mtx);
	i = -1;
	while (++i < i_end)
	{
		if (pthread_create(&wathcer[i].tid, NULL, life_of_watcher,
						   (void *) (wathcer + i)) == -1)
			return (-1);
	}
	pthread_mutex_unlock(&start_mtx);
	return (0);
}

int join_watcher_thread(t_watcher *watcher, int i_end)
{
	int	i;

	i = -1;
	while (++i < i_end)
	{
//		if (pthread_join(watcher[i].tid, NULL) == -1)
//			return (-1);
		if (pthread_detach(watcher[i].tid) == -1)
			return (-1);
	}
	return (0);
}
