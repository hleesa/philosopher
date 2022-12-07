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
	t_wathcer *wathcer = arg;

	while (TRUE)
	{
		if(get_msec() > wathcer->time_to_die + wathcer->philo->last_ate_msec )
		{
			wathcer->philo->state = DIE;
			print_state(wathcer->philo);
			return (NULL);
		}
	}
}

