/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:55:17 by salee2            #+#    #+#             */
/*   Updated: 2022/12/05 19:55:17 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_chopstick_mtx(t_common_philo *common_philo)
{
	int	i;

	common_philo->chopstick_mtx = malloc(sizeof(pthread_mutex_t) *
										common_philo->number_of_philosophers);
	if (common_philo->chopstick_mtx == NULL)
		return (-1);
	i = -1;
	while(++i < common_philo->number_of_philosophers)
	{
		if (pthread_mutex_init(common_philo->chopstick_mtx + i, NULL) == -1)
			return (-1);
	}
	return (0);
}

int	init_common_philo(int argc, char *argv[], t_common_philo *common_philo)
{
	if (!is_right_arg(argc, argv))
		return (-1);
	*common_philo = input_args(argc, argv);
	if (init_chopstick_mtx(common_philo) == -1)
		return (-1);
	common_philo->base_msec = get_msec();
	if (common_philo->base_msec == -1)
		return (-1);
	return (0);
}