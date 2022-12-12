/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:32:46 by salee2            #+#    #+#             */
/*   Updated: 2022/12/08 17:32:47 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_thread(t_common_philo *common_philo, t_philo *philo,t_watcher *watcher)
{
	const int num_of_philo = common_philo->number_of_philosophers;

	if (malloc_philo_thread(&philo, num_of_philo) == -1)
		return (-1);
	if (init_philo_thread(philo, common_philo) == -1)
		return (-1);
	if (malloc_watcher_thread(&watcher) == -1)
		return (-1);
	if (init_watcher_thread(watcher, philo) == -1)
		return (-1);
	if (create_philo_thread(philo, num_of_philo) == -1)
		return (-1);
	if (create_watcher_thread(watcher) == -1)
		return (-1);
	if (detach_philo_thread(philo, num_of_philo) == -1)
		return (-1);
	if (join_watcher_thread(watcher) == -1)
		return (-1);
	return (0);
}
