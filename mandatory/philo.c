/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:54 by salee2            #+#    #+#             */
/*   Updated: 2022/12/07 17:35:56 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_philo(t_philo *philo, t_common_philo *common_philo)
{
	print_state(common_philo->base_usec, philo->nth_philo, philo->state);
	philo->state = FORK;
}

void	eat_philo(t_philo *philo, t_common_philo *common_philo)
{
	pthread_mutex_lock(&common_philo->chopstick_mtx[philo->left_fork]);
	pthread_mutex_lock(&common_philo->chopstick_mtx[philo->right_fork]);

	print_state(common_philo->base_usec, philo->nth_philo, philo->state);
	print_state(common_philo->base_usec, philo->nth_philo, philo->state);

	philo->state = EAT;
	philo->last_ate_usec = get_usec();
	print_state(common_philo->base_usec, philo->nth_philo, philo->state);

	my_usleep(common_philo->time_to_eat);

	++philo->num_of_ate;
	philo->state = SLEEP;
	pthread_mutex_unlock(&common_philo->chopstick_mtx[philo->left_fork]);
	pthread_mutex_unlock(&common_philo->chopstick_mtx[philo->right_fork]);
}
void	sleep_philo(t_philo *philo, t_common_philo *common_philo)
{
	print_state(common_philo->base_usec, philo->nth_philo, philo->state);
	my_usleep(common_philo->time_to_sleep);
	philo->state = THINK;
}

void *life_of_philo(void *arg)
{
	t_philo *philo = arg;
	t_common_philo *common_philo = philo->common_philo;

	while (TRUE)
	{
		think_philo(philo, common_philo);
		eat_philo(philo, common_philo);
		sleep_philo(philo, common_philo);
	}
}
