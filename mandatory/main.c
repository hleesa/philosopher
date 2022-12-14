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

int	main(int argc, char *argv[])
{
	t_philo				*philo;
	t_common_philo		common_philo;
	t_watcher			*watcher;

	if (init_common_philo(argc, argv, &common_philo))
		return (EXIT_FAILURE);
	philo = NULL;
	watcher = NULL;
	if (create_thread(&common_philo, philo, watcher))
		return (EXIT_FAILURE);
	usleep(common_philo.number_of_philosophers * 500);
	return (0);
}
