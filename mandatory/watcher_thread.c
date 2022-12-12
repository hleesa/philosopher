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
	(void ) size;
	*wathcer = malloc(sizeof(t_watcher));
	if (*wathcer == NULL)
		return (-1);
	return (0);
}

int	init_watcher_thread(t_watcher *wathcer, t_philo *philo, t_common_watcher *common_watcher)
{
//	int			i;
//	const int	i_end = philo->common_philo->number_of_philosophers;
	const ll	time_to_die = philo[0].common_philo->time_to_die;

//	i = -1;
//	while (++i < i_end)
//	{
		wathcer->philo = philo;
		wathcer->time_to_die = time_to_die;
		wathcer->common_watcher = common_watcher;
//	}
	return (0);
}

int create_watcher_thread(t_watcher *wathcer, int i_end)
{
//	int	i;
	(void) i_end;
//	i = -1;
//	while (++i < i_end)
//	{
		if (pthread_create(&wathcer->tid, NULL, life_of_watcher,
						   (void *) (wathcer)) == -1)
			return (-1);
//	}
	return (0);
}

int join_watcher_thread(t_watcher *watcher, int i_end)
{
//	int	i;
	(void) i_end;
//	i = -1;
//	while (++i < i_end)
//	{
		if (pthread_join(watcher->tid, NULL) == -1)
			return (-1);
//	}
	return (0);
}
