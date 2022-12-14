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

t_bool	is_time_to_die(t_philo *philo, t_common_philo *common_philo, int* nth_philo)
{
	int			i;
	const int	i_end = common_philo->number_of_philosophers;
	const ll	time_to_die = common_philo->time_to_die;

	i = -1;
	while (++i < i_end)
	{
		if (get_usec() / 1000LL >  (time_to_die + philo[i].last_eat_usec) / 1000LL)
		{
			*nth_philo = i;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	is_time_to_finish_eating(t_philo *philo, t_common_philo *common_philo)
{
	int			i;
	int			num_of_must_eat;
	const int	i_end = common_philo->number_of_philosophers;

	num_of_must_eat = common_philo->number_of_times_each_philosopher_must_eat;
	i = -1;
	while (++i < i_end)
	{
		if (philo[i].num_of_eat < num_of_must_eat)
			return (FALSE);
	}
	return (TRUE);
}

void	*life_of_watcher(void *arg)
{
	t_watcher		*watcher;
	t_philo			*philo;
	t_common_philo	*common_philo;

	watcher = arg;
	philo = watcher->philo;
	common_philo = philo->common_philo;
	int nth_philo;
	while (TRUE)
	{
		if (is_time_to_die(philo, common_philo, &nth_philo))
		{
			print_state(common_philo->base_usec, nth_philo, DIE);
			return (NULL);
		}
		if (common_philo->number_of_times_each_philosopher_must_eat != -1)
			if (is_time_to_finish_eating(philo, common_philo))
				return (NULL);
	}
}
