/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:40:02 by salee2            #+#    #+#             */
/*   Updated: 2022/12/03 17:40:07 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_state(t_thread *philo)
{
	struct timeval cur_time;
	char *state_to_str[5] = {"is thinking", "has taken a fork", "is eating",
							 "is sleeping", "died"};
	gettimeofday(&cur_time, NULL);
	long long time_stamp = (cur_time.tv_usec -
			philo->common_data->base_time.tv_usec) / 1000;
	printf("%lld %d %s\n", time_stamp, philo->nth_philo + 1,
		   state_to_str[philo->state]);
}