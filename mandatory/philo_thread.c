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
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_philo_thread(t_philo *philo, t_common_philo *common_philo)
{
	int			i;
	const int	i_end = common_philo->number_of_philosophers;

	i = -1;
	while (++i < i_end)
	{
		if (pthread_mutex_init(&philo[i].last_eat_mtx, NULL))
			return (EXIT_FAILURE);
		if (pthread_mutex_init(&philo[i].num_of_eat_mtx, NULL))
			return (EXIT_FAILURE);
		philo[i].num_of_eat = 0LL;
		philo[i].nth_philo = i;
		philo[i].common_philo = common_philo;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % common_philo->number_of_philosophers;
		philo[i].last_eat_usec = get_usec();
		if (philo[i].last_eat_usec == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int create_philo_thread(t_philo *philo, int i_end)
{
	int	i;

	i = -1;
	while (++i < i_end)
	{
		if (pthread_create(&philo[i].tid, NULL, life_of_philo,
						   (void *) (philo + i)))
			return (EXIT_FAILURE);
		usleep(42);
	}
	return (EXIT_SUCCESS);
}

int detach_philo_thread(t_philo *philo, int i_end)
{
	int	i;

	i = -1;
	while (++i < i_end)
	{
		if (pthread_detach(philo[i].tid))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
