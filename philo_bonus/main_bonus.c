/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:25:25 by salee2            #+#    #+#             */
/*   Updated: 2023/01/07 18:25:26 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init(t_sem_name *sem_name, pid_t **pids, int num_of_philo)
{
	*pids = malloc(sizeof(pid_t) * num_of_philo);
	if (*pids == NULL)
	{
		printf("error: init\n");
		exit(EXIT_FAILURE);
	}
	init_sem_names(sem_name, num_of_philo);
	create_sem_names(sem_name, num_of_philo);
	init_semaphores(sem_name, num_of_philo);
	create_semaphores(sem_name, num_of_philo);
	return ;
}

int	main(int argc, char *argv[])
{
	t_philo			philo;
	t_common_philo	common;
	t_sem_name		sem_name;
	pid_t			*pids;

	init_common_philo(argc, argv, &common);
	init(&sem_name, &pids, common.number_of_philosophers);
	create_philo(&philo, &common, &pids, &sem_name);
	waitpid(-1, NULL, 0);
	kill_philo(pids, common.number_of_philosophers);
	delete_semaphores(&sem_name, common.number_of_philosophers);
	free_sem_name(&sem_name, common.number_of_philosophers);
	free(pids);
	return (0);
}
