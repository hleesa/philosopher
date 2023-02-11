/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:26:12 by salee2            #+#    #+#             */
/*   Updated: 2023/01/07 18:26:13 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_if_time_to_die(t_philo *philo, t_common_philo *common, \
sem_t *last_eat, sem_t *print)
{
	semaphore_wait(last_eat);
	if (get_usec() / 1000LL > (common->time_to_die + philo->last_eat_usec) \
	/ 1000LL)
	{
		print_state(philo, common, DIE, print);
		semaphore_post(last_eat);
		exit(EXIT_SUCCESS);
	}
	semaphore_post(last_eat);
	return ;
}

void	exit_if_finish_eating(t_philo *philo, t_common_philo *common, \
sem_t *num_of_eat)
{
	int			num_of_must_eat;

	num_of_must_eat = common->number_of_times_each_philosopher_must_eat;
	semaphore_wait(num_of_eat);
	if (philo->num_of_eat < num_of_must_eat)
	{
		semaphore_post(num_of_eat);
		return ;
	}
	semaphore_post(num_of_eat);
	exit(EXIT_SUCCESS);
}

void	*life_of_watcher(void *arg)
{
	t_philo			*philo;
	t_common_philo	*common;
	t_sems			sems;

	philo = arg;
	common = philo->common;
	sems.print = semaphore_get("/print");
	sems.last_eat = semaphore_get(philo->last_eat_sem_name);
	sems.num_of_eat = semaphore_get(philo->num_of_eat_sem_name);
	while (TRUE)
	{
		if (common->number_of_times_each_philosopher_must_eat != -1)
		{
			exit_if_time_to_die(philo, common, sems.last_eat, sems.print);
			exit_if_finish_eating(philo, common, sems.num_of_eat);
		}
		else
		{
			exit_if_time_to_die(philo, common, sems.last_eat, sems.print);
		}
		usleep(300);
	}
}
