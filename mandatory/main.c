/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:12:42 by salee2            #+#    #+#             */
/*   Updated: 2022/11/28 17:12:42 by salee2           ###   ########.fr       */
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
	const int left_fork = philo->nth_philo;
	const int right_fork = (philo->nth_philo + 1) % philo->common_data->number_of_philosophers;

	pthread_mutex_lock(&philo->common_data->chopstick_mtx[left_fork]);
	pthread_mutex_lock(&philo->common_data->chopstick_mtx[right_fork]);
	print_state(philo);
	print_state(philo);
	philo->state = EAT;
	print_state(philo);
	usleep(philo->common_data->time_to_eat * 1000);
	philo->state = SLEEP;
	pthread_mutex_unlock(&philo->common_data->chopstick_mtx[right_fork]);
	pthread_mutex_unlock(&philo->common_data->chopstick_mtx[left_fork]);
}
void	sleep_philo(t_thread *philo)
{
	print_state(philo);
	usleep(philo->common_data->time_to_sleep * 1000);
	philo->state = THINK;
}

void *thread_func(void *arg)
{
	t_thread *philo = arg;
	while (TRUE)
	{
		think_philo(philo);
		eat_philo(philo);
		sleep_philo(philo);
	}
}


int	main(int argc, char *argv[])
{
	t_common	common_data;
	t_thread	*philo;

	if (init_common_data(argc, argv, &common_data) == -1)
		return (0);
	philo = NULL;
	if (init_philo_thread(philo, &common_data) == -1)
		return (0);
	// 동적할당 헤제? , pthread_mutex_destroy
	return (0);
}
