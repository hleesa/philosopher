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

void print_state(void)
{
	// 프로그램 시작 시점에 gettimeofday(&base_time, NULL);
	struct timeval base_time, cur_time;
	int num_of_philo = 0;
	char *state_to_str[5] = {"is thinking", "has taken a fork", "is eating",
							 "is sleeping", "died"};

	gettimeofday(&cur_time, NULL);
	long long time_stamp = (cur_time.tv_usec - base_time.tv_usec) / 1000;
	printf("%lld %d %s", time_stamp, num_of_philo,
		   state_to_str[num_of_philo]);
}