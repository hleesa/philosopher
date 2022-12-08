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
	t_common_watcher	common_watcher;

	if (init_common_data(argc, argv, &common_philo, &common_watcher) == -1)
		return (-1);
	philo = NULL;
	watcher = NULL;
	if (create_thread(&common_philo, philo, &common_watcher, watcher) == -1)
		return (-1);
	return (0);
}
