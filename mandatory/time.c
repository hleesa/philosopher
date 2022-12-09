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

//void	msleep(ll msec)
//{
//	const ll base_msec = get_msec();
//
//	while(base_msec + msec >= get_msec())
//	{}
//	return ;
//}

//ll	get_msec(void)
//{
//	struct timeval	cur_time;
//
//	if (gettimeofday(&cur_time, NULL) == -1)
//		return (-1LL);
//	return (cur_time.tv_sec * 1000LL + cur_time.tv_usec / 1000LL);
//}

void	my_usleep(ll usec)
{
	const ll base_usec = get_usec();

	while(base_usec + usec >= get_usec());
	return ;
}


ll	get_usec(void)
{
	struct timeval	cur_time;

	if (gettimeofday(&cur_time, NULL) == -1)
		return (-1LL);
	return (cur_time.tv_sec * 1000000LL + cur_time.tv_usec);
}