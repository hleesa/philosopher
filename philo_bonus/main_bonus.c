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

void	init(pid_t **pids, int num_of_philo)
{
	*pids = malloc(sizeof(pid_t) * num_of_philo);
	if (*pids == NULL)
	{
		printf("error: init\n");
		exit(EXIT_FAILURE);
	}
	init_semaphores(num_of_philo);
	create_semaphores(num_of_philo);
	return ;
}

int	main(int argc, char *argv[])
{
	t_philo			philo;
	t_common_philo	common;
	pid_t			*pids;

	init_common_philo(argc, argv, &common);
	init(&pids, common.number_of_philosophers);
	create_philo(&philo, &common, &pids);
	waitpid(-1, NULL, 0);
	kill_philo(pids, common.number_of_philosophers);
	delete_semaphores();
	free(pids);
	return (0);
}
