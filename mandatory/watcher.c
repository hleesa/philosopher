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
	int i_end = wathcer->philo->common_philo->number_of_philosophers;
	t_common_philo *common_philo = wathcer->philo->common_philo;
	t_philo *philo = wathcer->philo;

	while (TRUE)
	{
		for(int i=0; i< i_end; ++i)
		{
			if (get_usec() >
				wathcer->time_to_die + philo[i].last_ate_usec){
				print_state(common_philo->base_usec,
							wathcer->philo->nth_philo, DIE);
				return (NULL);
			}
		}
	}

}

