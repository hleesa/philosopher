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
	t_philo			*philo;
	t_common_philo	common;

	if (init_common_philo(argc, argv, &common))
		return (EXIT_FAILURE);
	sem_t *fork = sem_open("/myfork", O_CREAT, 0660, common.number_of_philosophers);
	if (fork == SEM_FAILED)
	{
		perror("sem_open");
		return EXIT_FAILURE;
	}
	for (int i = 1; i <= common.number_of_philosophers; ++i)
	{

	}
	philo = NULL;
	if (create_thread(philo, &common))
		return (EXIT_FAILURE);
	return (0);
}
