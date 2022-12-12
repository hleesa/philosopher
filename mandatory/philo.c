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

void	think_philo(t_philo *philo, t_common_philo *common_philo, const char *state_to_str[5])
{
	print_state(common_philo->base_usec, philo->nth_philo, state_to_str[THINK]);
}

void	eat_philo(t_philo *philo, t_common_philo *common_philo, const char *state_to_str[5])
{
	pthread_mutex_lock(&common_philo->chopstick_mtx[philo->left_fork]);
	pthread_mutex_lock(&common_philo->chopstick_mtx[philo->right_fork]);

	print_state(common_philo->base_usec, philo->nth_philo, state_to_str[FORK]);
	print_state(common_philo->base_usec, philo->nth_philo, state_to_str[FORK]);

	pthread_mutex_lock(&philo->last_eat_mtx);
	philo->last_eat_usec = get_usec();
	pthread_mutex_unlock(&philo->last_eat_mtx);

	print_state(common_philo->base_usec, philo->nth_philo, state_to_str[EAT]);

	my_usleep(common_philo->time_to_eat);

	pthread_mutex_lock(&philo->num_of_eat_mtx);
	++philo->num_of_eat;
	pthread_mutex_unlock(&philo->num_of_eat_mtx);

	pthread_mutex_unlock(&common_philo->chopstick_mtx[philo->left_fork]);
	pthread_mutex_unlock(&common_philo->chopstick_mtx[philo->right_fork]);
}
void	sleep_philo(t_philo *philo, t_common_philo *common_philo, const char *state_to_str[5])
{
	print_state(common_philo->base_usec, philo->nth_philo, state_to_str[SLEEP]);
	my_usleep(common_philo->time_to_sleep);
}

void *life_of_philo(void *arg)
{
	t_philo *philo = arg;
	t_common_philo *common_philo = philo->common_philo;
	const char *state_to_str[5] = {"is thinking", "has taken a fork",
								   "is eating", "is sleeping", "died"};
	while (TRUE)
	{
		think_philo(philo, common_philo, state_to_str);
		eat_philo(philo, common_philo, state_to_str);
		sleep_philo(philo, common_philo, state_to_str);
	}
}
