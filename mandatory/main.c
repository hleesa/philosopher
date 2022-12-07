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
	t_common	common_philo;
	t_thread	*philo;

	if (init_common_philo(argc, argv, &common_philo) == -1)
		return (0);
	philo = NULL;
	if (create_philo(philo, &common_philo) == -1)
		return (0);
	// add monitor
	while(TRUE)
	{

	}
	return (0);
}
