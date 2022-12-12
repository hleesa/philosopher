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

void print_state(t_philo *philo, ll base_usec, int nth_philo, enum e_tstate state)
{
	const char *state_to_str[5] = {"is thinking", "has taken a fork",
								   "is eating", "is sleeping", "died"};
	const ll cur_usec = get_usec();

	if (cur_usec == -1LL)
		return ;
	ll time_stamp = cur_usec - base_usec;
    if(state == EAT)
    {
        pthread_mutex_lock(&philo->common_philo->print_mtx);
        philo->error_usec += (time_stamp) % (philo->common_philo->time_to_eat);
        pthread_mutex_unlock(&philo->common_philo->print_mtx);
    }
    else if(state == SLEEP)
    {
        pthread_mutex_lock(&philo->common_philo->print_mtx);
        philo->error_usec += (time_stamp) % (philo->common_philo->time_to_sleep);
        pthread_mutex_unlock(&philo->common_philo->print_mtx);
    }
    printf("%lld %d %s\n", time_stamp/1000LL - time_stamp/1000LL%10L, nth_philo + 1,
		   state_to_str[state]);
}