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

void	think_philo(t_thread *philo)
{
	print_state(philo);
	philo->state = FORK;
}

void	eat_philo(t_thread *philo)
{
	pthread_mutex_lock(&philo->common_philo->chopstick_mtx[philo->left_fork]);
	pthread_mutex_lock(&philo->common_philo->chopstick_mtx[philo->right_fork]);
	print_state(philo);
	print_state(philo);
	philo->state = EAT;
	print_state(philo);
	usleep(philo->common_philo->time_to_eat * 1000);
	philo->state = SLEEP;
	pthread_mutex_unlock(&philo->common_philo->chopstick_mtx[philo->right_fork]);
	pthread_mutex_unlock(&philo->common_philo->chopstick_mtx[philo->left_fork]);
}
void	sleep_philo(t_thread *philo)
{
	print_state(philo);
	usleep(philo->common_philo->time_to_sleep * 1000);
	philo->state = THINK;
}

void *life_of_philo(void *arg)
{
	t_thread *philo = arg;

	while (TRUE)
	{
		think_philo(philo);
		eat_philo(philo);
		sleep_philo(philo);
	}
}
