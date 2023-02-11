/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_philo_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:30:44 by salee2            #+#    #+#             */
/*   Updated: 2023/02/11 14:30:46 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	think_philo(t_philo *philo, t_common_philo *common, sem_t *print)
{
	print_state(philo, common, THINK, print);
}

void	eat_philo(t_philo *philo, t_common_philo *common, t_sems *sems, \
t_ll *saved_usec)
{
	semaphore_wait(sems->forks);
	semaphore_wait(sems->forks);
	*saved_usec = get_usec();
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
	t_ll	saved_usec;

	sems.forks = semaphore_get("/forks");
	sems.print = semaphore_get("/print");
	sems.last_eat = semaphore_get("/last_eat");
	sems.num_of_eat = semaphore_get("/num_of_eat");
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
		eat_philo(philo, common, &sems, &saved_usec);
		sleep_philo(philo, common, sems.print);
		philo->error_usec += (get_usec() - saved_usec
				- common->time_to_sleep - common->time_to_eat);
	}
}
