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
	t_common_philo	common_philo;
	t_philo	*philo;
	t_wathcer *wathcer;

	if (init_common_philo(argc, argv, &common_philo) == -1)
		return (0);
	philo = NULL;
	if (create_philo(philo, &common_philo) == -1)
		return (0);
	wathcer = NULL;
	if(create_watcher(wathcer, philo) == -1)
		return (0);
	return (0);
}
