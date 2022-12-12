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
	t_philo *philo = wathcer->philo;
	t_common_philo *common_philo = philo->common_philo;
	ll time_to_die = common_philo->time_to_die;
	int i_end = common_philo->number_of_philosophers;

	while (TRUE)
	{
		for(int i=0; i< i_end; ++i)
		{
			if (get_usec() >
				time_to_die + philo[i].last_eat_usec){
				print_state(common_philo->base_usec,
							wathcer->philo->nth_philo, DIE);
				return (NULL);
			}
		}
		if (common_philo->number_of_times_each_philosopher_must_eat != -1)
		{
			for(int i=0; i< i_end; ++i)
			{
				t_bool is_eat_all = TRUE;
				if (philo[i].num_of_eat <= common_philo->number_of_times_each_philosopher_must_eat)
				{
					is_eat_all = FALSE;
					break;
				}
				if (is_eat_all)
					return (NULL);
			}
		}
	}

}
