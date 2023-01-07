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

t_bool	is_time_to_die(t_philo *philo, t_common_philo *common)
{
	int			i;
	const int	i_end = common->number_of_philosophers;
	const t_ll	time_to_die = common->time_to_die;

	i = -1;
	while (++i < i_end)
	{
		pthread_mutex_lock(&philo[i].last_eat_mtx);
		if (get_usec() > (time_to_die + philo[i].last_eat_usec))
		{
			print_state(philo, common, DIE);
			pthread_mutex_unlock(&philo[i].last_eat_mtx);
			return (TRUE);
		}
		pthread_mutex_unlock(&philo[i].last_eat_mtx);
	}
	return (FALSE);
}

t_bool	is_time_to_finish_eating(t_philo *philo, t_common_philo *common)
{
	int			i;
	int			num_of_must_eat;
	const int	i_end = common->number_of_philosophers;

	num_of_must_eat = common->number_of_times_each_philosopher_must_eat;
	i = -1;
	while (++i < i_end)
	{
		pthread_mutex_lock(&philo[i].num_of_eat_mtx);
		if (philo[i].num_of_eat < num_of_must_eat)
		{
			pthread_mutex_unlock(&philo[i].num_of_eat_mtx);
			return (FALSE);
		}
		pthread_mutex_unlock(&philo[i].num_of_eat_mtx);
	}
	pthread_mutex_lock(&common->end_mtx);
	common->is_end = TRUE;
	pthread_mutex_unlock(&common->end_mtx);
	return (TRUE);
}

int	life_of_watcher(t_philo *philo, t_common_philo *common)
{
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
	if (join_philo_thread(philo, common->number_of_philosophers))
		return (EXIT_FAILURE);
	free(philo);
	free(common->fork_mtx);
	return (EXIT_SUCCESS);
}
