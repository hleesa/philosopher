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

#include "philo_bonus.h"

int	init_fork_mtx(t_common_philo *common)
{
	int			i;
	const int	size = common->number_of_philosophers;

	common->fork_mtx = malloc(sizeof(pthread_mutex_t) * size);
	if (common->fork_mtx == NULL)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < size)
	{
		if (pthread_mutex_init(common->fork_mtx + i, NULL))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_common_philo(int argc, char *argv[], t_common_philo *common)
{
	if (!is_right_arg(argc, argv))
		return (EXIT_FAILURE);
	*common = input_args(argc, argv);
	common->base_usec = get_usec();
	common->is_end = FALSE;
	if (pthread_mutex_init(&common->end_mtx, NULL))
		return (EXIT_FAILURE);
	if (init_fork_mtx(common))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
