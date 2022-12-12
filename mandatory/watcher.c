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
	t_common_philo *common_philo = watcher->philo->common_philo;
	int i_end = common_philo->number_of_philosophers;
	t_philo *philo = watcher->philo;

	while (TRUE)
	{
		for(int i=0; i<i_end; ++i)
		{
			if (get_usec() >watcher->time_to_die + philo[i].last_ate_usec)
			{
				pthread_mutex_lock(&common_philo->print_mtx);
				print_state(common_philo->base_usec,
							philo->nth_philo, DIE);
				pthread_mutex_unlock(&common_philo->print_mtx);
				return (NULL);
			}
		}
	}
}

