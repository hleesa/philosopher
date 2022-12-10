/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:17:06 by salee2            #+#    #+#             */
/*   Updated: 2022/12/07 19:17:07 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *life_of_watcher(void *arg)
{
	t_watcher *watcher = arg;
	t_common_watcher *common_watcher = watcher->common_watcher;
	t_common_philo *common_philo = watcher->philo->common_philo;
	t_bool is_must_eat = common_watcher->is_must_eat;
	ll num_of_must_eat = watcher->philo->common_philo->number_of_times_each_philosopher_must_eat;

	if (is_must_eat)
	{
		while (TRUE)
		{
			if (get_usec() > watcher->time_to_die + watcher->philo->last_ate_usec)
			{
				pthread_mutex_lock(&common_philo->print_mtx);
				print_state(common_philo->base_usec,
							watcher->philo->nth_philo, DIE);
				pthread_mutex_unlock(&common_philo->print_mtx);

				return (NULL);
			}
			if (watcher->philo->num_of_ate == num_of_must_eat)
			{
				++common_watcher->num_of_eat_all_philo;
				if (common_watcher->num_of_eat_all_philo >= common_philo->number_of_philosophers)
					return (NULL);
			}
		}
	}
	else
	{
		while (TRUE)
		{
			if (get_usec() > watcher->time_to_die + watcher->philo->last_ate_usec)
			{
				pthread_mutex_lock(&common_philo->print_mtx);
				print_state(common_philo->base_usec,
							watcher->philo->nth_philo, DIE);
				pthread_mutex_unlock(&common_philo->print_mtx);
				return (NULL);
			}
		}
	}
//	(void)arg;
//	while (TRUE);

}

