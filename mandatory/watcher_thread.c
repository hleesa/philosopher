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

int	malloc_watcher_thread(t_watcher **wathcer, ll num_of_must_eat)
{
	*wathcer = malloc(sizeof(t_watcher));
	if (*wathcer == NULL)
		return (-1);
	if (num_of_must_eat != -1LL)
	{
		(*wathcer)->opt = malloc(sizeof(t_watcher));
		printf("%p:\n", (*wathcer)->opt);
		if ((*wathcer)->opt == NULL)
			return (-1);
	}
	else
		(*wathcer)->opt = NULL;
	return (0);
}

int	init_watcher_thread(t_watcher *wathcer, t_philo *philo)
{
	wathcer->philo = philo;
	if (wathcer->opt != NULL)
		wathcer->opt->philo = philo;
	printf("%p:\n", wathcer->opt);
	return (0);
}

int create_watcher_thread(t_watcher *wathcer)
{
	if (wathcer->opt != NULL)
	{
		if (pthread_create(&wathcer->opt->tid, NULL, life_of_watcher_option,
						   (void *) (wathcer->opt)) == -1)
			return (-1);
	}
	if (pthread_create(&wathcer->tid, NULL, life_of_watcher,
					   (void *) (wathcer)) == -1)
		return (-1);
	return (0);
}

int join_watcher_thread(t_watcher *watcher)
{
	if (watcher->opt != NULL)
	{
		if (pthread_join(watcher->opt->tid, NULL) == -1)
			return (-1);
	}
	if (pthread_join(watcher->tid, NULL) == -1)
		return (-1);
	return (0);
}
