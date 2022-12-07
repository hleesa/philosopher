/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:39:56 by salee2            #+#    #+#             */
/*   Updated: 2022/12/07 17:39:59 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_philo_thread(t_thread **philo, t_common *common_philo)
{
	*philo = malloc(sizeof(t_thread) * common_philo->number_of_philosophers);
	if (*philo == NULL)
		return (-1);
	return (0);
}

int	init_philo_thread(t_thread *philo, t_common *common_philo)
{
	int	i;

	i = -1;
	while (++i < common_philo->number_of_philosophers)
	{
		philo[i].nth_philo = i;
		philo[i].state = THINK;
		philo[i].common_philo = common_philo;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % common_philo->number_of_philosophers;
		philo[i].last_ate_msec = get_msec();
		if (philo[i].last_ate_msec == -1)
			return (-1);
	}
	return (0);
}

int create_philo_thread(t_thread *philo)
{
	int i;

	i = -1;
	while (++i < philo->common_philo->number_of_philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, life_of_philo,
						   (void *) (philo + i)) == -1)
			return (-1);
	}
	return (0);
}

int detach_philo_thread(t_thread *philo)
{
	int	i;

	i = -1;
	while (++i < philo->common_philo->number_of_philosophers)
	{
		if (pthread_detach(philo[i].tid) == -1)
			return (-1);
	}
	return (0);
}

int create_philo(t_thread *philo, t_common *common_philo)
{
	if (malloc_philo_thread(&philo, common_philo) == -1)
		return (-1);
	if (init_philo_thread(philo, common_philo) == -1)
		return (-1);
	if (create_philo_thread(philo) == -1)
		return (-1);
	if (detach_philo_thread(philo) == -1)
		return (-1);
	return (0);
}
