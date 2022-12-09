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

void print_state(ll base_usec, int nth_philo, enum e_tstate state)
{
	const char *state_to_str[5] = {"is thinking", "has taken a fork",
								   "is eating", "is sleeping", "died"};
	const ll cur_usec = get_usec();

	if (cur_usec == -1LL)
		return ;
	ll time_stamp = cur_usec - base_usec;
	printf("%lld %d %s\n", time_stamp / 1000LL, nth_philo + 1,
		   state_to_str[state]);
}