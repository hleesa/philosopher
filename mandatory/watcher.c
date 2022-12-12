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

t_bool is_time_to_die(t_philo *philo, t_common_philo *common_philo)
{
	int			i;
	const int	i_end = common_philo->number_of_philosophers;
	ll			time_to_die = common_philo->time_to_die;

	i = -1;
	while (++i < i_end)
	{
		if (get_usec() > time_to_die + philo[i].last_eat_usec)
		{
			print_state(common_philo->base_usec, philo->nth_philo, DIE);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool is_time_to_finish_eating(t_philo *philo, t_common_philo *common_philo)
{
	int			i;
	const int	i_end = common_philo->number_of_philosophers;

	i = -1;
	while (++i < i_end)
	{
		if (philo[i].num_of_eat < common_philo->number_of_times_each_philosopher_must_eat)
			return (FALSE);
	}
	return (TRUE);
}

void *life_of_watcher(void *arg)
{
	t_watcher		*wathcer = arg;
	t_philo			*philo = wathcer->philo;
	t_common_philo	*common_philo = philo->common_philo;

	while (TRUE)
	{
		if (is_time_to_die(philo, common_philo))
			return (NULL);
		if (common_philo->number_of_times_each_philosopher_must_eat != -1)
			if (is_time_to_finish_eating(philo, common_philo))
				return (NULL);
	}
}
