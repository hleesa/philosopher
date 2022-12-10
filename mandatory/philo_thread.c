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

int	malloc_philo_thread(t_philo **philo, int size)
{
	*philo = malloc(sizeof(t_philo) * size);
	if (*philo == NULL)
		return (-1);
	return (0);
}

int	init_philo_thread(t_philo *philo, t_common_philo *common_philo)
{
	int			i;
	const int	i_end = common_philo->number_of_philosophers;

	i = -1;
	while (++i < i_end)
	{
		philo[i].num_of_ate = 0;
		philo[i].nth_philo = i;
		philo[i].state = THINK;
		philo[i].common_philo = common_philo;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % common_philo->number_of_philosophers;
		philo[i].last_ate_usec = get_usec();
		if (philo[i].last_ate_usec == -1)
			return (-1);
	}
	return (0);
}

int create_philo_thread(t_philo *philo, int i_end)
{
	int	i;

	pthread_mutex_t start_mtx;
	pthread_mutex_init(&start_mtx, NULL);
	pthread_mutex_lock(&start_mtx);
	i = -1;
	while (++i < i_end)
	{
		if (pthread_create(&philo[i].tid, NULL, life_of_philo,
						   (void *) (philo + i)) == -1)
			return (-1);
	}
	philo->common_philo->base_usec = get_usec();
	for(int i=0; i<i_end; ++i)
	{
		philo[i].last_ate_usec = philo->common_philo->base_usec;
	}
	pthread_mutex_unlock(&start_mtx);
	return (0);
}

int detach_philo_thread(t_philo *philo, int i_end)
{
	int			i;

	i = -1;
	while (++i < i_end)
	{
//		if (pthread_detach(philo[i].tid) == -1)
//			return (-1);
		if (pthread_join(philo[i].tid, NULL) == -1)
			return (-1);

	}
	return (0);
}
