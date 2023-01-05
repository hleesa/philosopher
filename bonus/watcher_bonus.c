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

#include "philo_bonus.h"

t_bool	is_time_to_die(t_philo *philo, t_common_philo *common)
{
	if (get_usec() > (common->time_to_die + philo->last_eat_usec))
	{
		print_state(philo, common, DIE);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	is_time_to_finish_eating(t_philo *philo, t_common_philo *common)
{
	int			num_of_must_eat;

	num_of_must_eat = common->number_of_times_each_philosopher_must_eat;
	if (philo->num_of_eat < num_of_must_eat)
	{
		return (FALSE);
	}
	return (TRUE);
}

void *life_of_watcher(void *arg)
{
	t_philo			*philo;
	t_common_philo	*common;

	philo = arg;
	common = philo->common;
	while (TRUE)
	{
		if (is_time_to_die(philo, common))
			break ;
		if (common->number_of_times_each_philosopher_must_eat != -1)
		{
			if (is_time_to_finish_eating(philo, common))
				break ;
		}
		usleep(300);
	}
	return (NULL);
}
