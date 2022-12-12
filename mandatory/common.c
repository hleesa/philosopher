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
	int			i;
	const int	size = common_philo->number_of_philosophers;

	common_philo->chopstick_mtx = malloc(sizeof(pthread_mutex_t) * size);
	if (common_philo->chopstick_mtx == NULL)
		return (EXIT_FAILURE);
	i = -1;
	while(++i < size)
	{
		if (pthread_mutex_init(common_philo->chopstick_mtx + i, NULL))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_common_philo(int argc, char *argv[], t_common_philo *common_philo)
{
	if (!is_right_arg(argc, argv))
		return (EXIT_FAILURE);
	*common_philo = input_args(argc, argv);
	if (init_chopstick_mtx(common_philo))
		return (EXIT_FAILURE);
	common_philo->base_usec = get_usec();
	if (common_philo->base_usec == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
