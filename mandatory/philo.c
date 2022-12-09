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

void	think_philo(t_philo *philo)
{
	philo->saved_usec = get_usec();
	print_state(philo->base_usec, philo->nth_philo, philo->state);
	philo->state = FORK;
}

void	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->common_philo->chopstick_mtx[philo->left_fork]);
	pthread_mutex_lock(&philo->common_philo->chopstick_mtx[philo->right_fork]);

	print_state(philo->base_usec, philo->nth_philo, philo->state);
	print_state(philo->base_usec, philo->nth_philo, philo->state);
	philo->last_ate_usec = get_usec();
	philo->state = EAT;
	print_state(philo->base_usec, philo->nth_philo, philo->state);

	my_usleep(philo->common_philo->time_to_eat);

	++philo->num_of_ate;
	philo->state = SLEEP;
	pthread_mutex_unlock(&philo->common_philo->chopstick_mtx[philo->right_fork]);
	pthread_mutex_unlock(&philo->common_philo->chopstick_mtx[philo->left_fork]);
}
void	sleep_philo(t_philo *philo)
{
	print_state(philo->base_usec, philo->nth_philo, philo->state);
	my_usleep(philo->common_philo->time_to_sleep);
	philo->state = THINK;
	philo->base_usec += (get_usec() - philo->saved_usec - philo->common_philo->time_to_eat
			- philo->common_philo->time_to_sleep);
}

void *life_of_philo(void *arg)
{
	t_philo *philo = arg;

	while (TRUE)
	{
		think_philo(philo);
		eat_philo(philo);
		sleep_philo(philo);
	}
}
