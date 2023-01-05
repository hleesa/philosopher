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

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_philo			philo;
	t_common_philo	common;
	pid_t			pid;
	int 			i;

	if (init_common_philo(argc, argv, &common))
		return (EXIT_FAILURE);
	sem_t *forks = sem_open("/forks", O_CREAT, 0660, common.number_of_philosophers);
	if (forks == SEM_FAILED)
	{
		return EXIT_FAILURE;
	}
	i = -1;
	while( ++i < common.number_of_philosophers)
	{
		pid = fork();
		exit_if_fork_error(pid);
		if (pid == 0)
		{
			// set philo info
			philo.nth_philo = i + 1;
			philo.num_of_eat = 0;
			philo.last_eat_usec = get_usec();
			philo.common = &common;
			pthread_t	tid;
			if (pthread_create(tid, NULL, life_of_watcher, (void *)(&philo)))
				return (EXIT_FAILURE);
			life_of_philo(&philo, &common);
			if (pthread_join(tid, NULL))
				return (EXIT_FAILURE);
		}
		else
		{
			// wait
			waitpid(-1, 0, 0);
		}
	}
	// life of philo
	return (0);
}
