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

#include "philo_bonus.h"

int	think_philo(t_philo *philo, t_common_philo *common)
{
	return (print_state(philo, common, THINK));
}

int	eat_philo(t_philo *philo, t_common_philo *common)
{
	sem_t forks = sem_open("/forks", 0);

	if(forks == SEM_FAILED)
		exit(EXIT_FAILURE);
	if (sem_wait(forks) == -1 || sem_wait(forks) == -1)
		exit(EXIT_FAILURE);

	if (print_state(philo, common, FORK))
		return (EXIT_FAILURE);
	if (print_state(philo, common, FORK))
		return (EXIT_FAILURE);
	if (print_state(philo, common, EAT))
		return (EXIT_FAILURE);
	philo->last_eat_usec = get_usec() + philo->error_usec;
	my_usleep(common->time_to_eat);
	++philo->num_of_eat;

	if (sem_post(forks) == -1 || sem_post(forks) == -1)
		exit(EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

int	sleep_philo(t_philo *philo, t_common_philo *common)
{
	if (print_state(philo, common, SLEEP))
		return (EXIT_FAILURE);
	my_usleep(common->time_to_sleep);
	return (EXIT_SUCCESS);
}

void	*life_of_philo(t_philo *philo, t_common_philo *common)
{
	if (common->number_of_philosophers == 1)
	{
		print_state(philo, common, FORK);
		my_usleep(common->time_to_die);
		print_state(philo, common, DIE);
		return (NULL);
	}
	while (TRUE)
	{
		if (think_philo(philo, common))
			return (NULL);
		philo->saved_usec = get_usec();
		if (eat_philo(philo, common))
			return (NULL);
		if (sleep_philo(philo, common))
			return (NULL);
		philo->error_usec += (get_usec() - philo->saved_usec
				- common->time_to_sleep - common->time_to_eat);
	}
}
