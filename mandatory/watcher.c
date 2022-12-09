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
	t_watcher *wathcer = arg;
	t_bool is_must_eat = wathcer->common_watcher->is_must_eat;
	ll num_of_must_eat = wathcer->philo->common_philo->number_of_times_each_philosopher_must_eat;

	if (is_must_eat)
	{
		while (TRUE)
		{
			if (get_usec() > wathcer->time_to_die + wathcer->philo->last_ate_usec)
			{
				print_state(wathcer->philo->common_philo->base_usec,
							wathcer->philo->nth_philo, DIE);
				return (NULL);
			}
			if (wathcer->philo->num_of_ate == num_of_must_eat)
			{
				++wathcer->common_watcher->num_of_eat_all_philo;
				if (wathcer->common_watcher->num_of_eat_all_philo >= wathcer->philo->common_philo->number_of_philosophers)
					return (NULL);
			}
		}
	}
	else
	{
		while (TRUE)
		{
			if (get_usec() > wathcer->time_to_die + wathcer->philo->last_ate_usec)
			{
				print_state(wathcer->philo->common_philo->base_usec,
							wathcer->philo->nth_philo, DIE);
				return (NULL);
			}
		}
	}
}

