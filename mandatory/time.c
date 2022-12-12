/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:09:23 by salee2            #+#    #+#             */
/*   Updated: 2022/12/06 16:09:24 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(ll usec)
{
	const ll base_usec = get_usec();

	while(base_usec + usec >= get_usec())
		usleep(50);
	return ;
}

ll	get_usec(void)
{
	struct timeval	cur_time;

	if (gettimeofday(&cur_time, NULL) == -1)
		return (-1LL);
	return (cur_time.tv_sec * 1000000LL + cur_time.tv_usec);
}