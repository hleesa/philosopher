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

void print_state(t_philo *philo)
{
	const char *state_to_str[5] = {"is thinking", "has taken a fork",
								   "is eating", "is sleeping", "died"};
	const ll cur_msec = get_msec();

	if(cur_msec == -1LL)
		return ;
	ll time_stamp = cur_msec - philo->common_philo->base_msec;
	printf("%lld %d %s\n", time_stamp, philo->nth_philo + 1,
		   state_to_str[philo->state]);
}