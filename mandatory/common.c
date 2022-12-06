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

int	init_chopstick_mtx(t_common *common_data)
{
	int	i;

	common_data->chopstick_mtx = malloc(sizeof(pthread_mutex_t) *
										common_data->number_of_philosophers);
	if (common_data->chopstick_mtx == NULL)
		return (-1);
	i = -1;
	while(++i < common_data->number_of_philosophers)
	{
		if (pthread_mutex_init(common_data->chopstick_mtx + i, NULL) == -1)
			return (-1);
	}
	return (0);
}

int	init_common_data(int argc, char *argv[], t_common *common_data)
{
	if (!is_right_arg(argc, argv))
		return (-1);
	*common_data = input_args(argc, argv);
	if (init_chopstick_mtx(common_data) == -1)
		return (-1);
	common_data->base_msec = get_msec();
	if (common_data->base_msec == -1)
		return (-1);
	return (0);
}