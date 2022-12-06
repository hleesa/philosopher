/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:31:41 by salee2            #+#    #+#             */
/*   Updated: 2022/12/05 20:31:42 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philo_thread(t_thread *philo, t_common *common_data)
{
	int	i;

	philo = malloc(sizeof(t_thread) * common_data->number_of_philosophers);
	if (philo == NULL)
		return (-1);
	i = -1;
	while(++i < common_data->number_of_philosophers)
	{
		philo[i].nth_philo = i;
		philo[i].state = THINK;
		philo[i].common_data = common_data;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % common_data->number_of_philosophers;
		philo[i].last_ate_msec = get_msec();
		if (philo[i].last_ate_msec == -1)
			return (-1);
		if (pthread_create(&philo[i].tid, NULL, thread_func, (void*)(philo+i)) == -1)
			return (-1);
	}
	for(int i=0; i<philo->common_data->number_of_philosophers; ++i)
	{
		if (pthread_join(philo[i].tid, NULL) == -1)
			return (-1);
	}
	return (0);
}

