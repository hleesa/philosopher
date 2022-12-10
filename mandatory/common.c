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
		return (-1);
	if (pthread_mutex_init(&common_philo->print_mtx, NULL) == -1)
		return (-1);
	i = -1;
	while(++i < size)
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
	common_philo->base_usec = get_usec();
	if (common_philo->base_usec == -1)
		return (-1);
	return (0);
}

void	init_common_watcher(int argc, t_common_watcher *common_watcher)
{
	if (argc == 6)
		common_watcher->is_must_eat = TRUE;
	else
		common_watcher->is_must_eat = FALSE;
	common_watcher->num_of_eat_all_philo = 0;
}

int init_common_data(int argc, char *argv[],
				 t_common_philo *common_philo, t_common_watcher *watcher)
{
	if (init_common_philo(argc, argv, common_philo) == -1)
		return (-1);
	init_common_watcher(argc, watcher);
	return (0);
}