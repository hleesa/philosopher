/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:19:50 by salee2            #+#    #+#             */
/*   Updated: 2023/03/01 18:19:50 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(t_ll usec)
{
	const t_ll	base_usec = get_usec();

	while (base_usec + usec >= get_usec())
		usleep(100);
	return ;
}

t_ll	get_usec(void)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	return (cur_time.tv_sec * 1000000LL + cur_time.tv_usec);
}
