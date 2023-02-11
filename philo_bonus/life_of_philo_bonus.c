/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:25:33 by salee2            #+#    #+#             */
/*   Updated: 2023/01/07 18:25:35 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	think_philo(t_philo *philo, t_common_philo *common, sem_t *print)
{
	print_state(philo, common, THINK, print);
}

void	eat_philo(t_philo *philo, t_common_philo *common, t_sems *sems)
{
	semaphore_wait(sems->forks);
	semaphore_wait(sems->forks);
	philo->saved_usec = get_usec();
	print_state(philo, common, FORK, sems->print);
	print_state(philo, common, FORK, sems->print);
	print_state(philo, common, EAT, sems->print);
	semaphore_wait(sems->last_eat);
	philo->last_eat_usec = get_usec() + philo->error_usec;
	semaphore_post(sems->last_eat);
	my_usleep(common->time_to_eat);
	semaphore_wait(sems->num_of_eat);
	++philo->num_of_eat;
	semaphore_post(sems->num_of_eat);
	semaphore_post(sems->forks);
	semaphore_post(sems->forks);
}

void	sleep_philo(t_philo *philo, t_common_philo *common, sem_t *print)
{
	print_state(philo, common, SLEEP, print);
	my_usleep(common->time_to_sleep);
}

void	life_of_philo(t_philo *philo, t_common_philo *common)
{
	t_sems	sems;

	sems.forks = semaphore_get("/forks");
	sems.print = semaphore_get("/print");
	sems.last_eat = semaphore_get(philo->last_eat_sem_name);
	sems.num_of_eat = semaphore_get(philo->num_of_eat_sem_name);
	if (common->number_of_philosophers == 1)
	{
		print_state(philo, common, FORK, sems.print);
		my_usleep(common->time_to_die);
		print_state(philo, common, DIE, sems.print);
		exit(EXIT_SUCCESS);
	}
	while (TRUE)
	{
		think_philo(philo, common, sems.print);
		eat_philo(philo, common, &sems);
		sleep_philo(philo, common, sems.print);
		philo->error_usec += (get_usec() - philo->saved_usec
				- common->time_to_sleep - common->time_to_eat);
	}
}
