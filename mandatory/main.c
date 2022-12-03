/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:12:42 by salee2            #+#    #+#             */
/*   Updated: 2022/11/28 17:12:42 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "philo.h"

//static int glob = 0;
//static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
//
//static void *
//threadFunc(void *arg)
//{
//	int loops = *((int *) arg);
//	int loc, j, s;
//
//	for (j = 0; j < loops; ++j)
//	{
//		s = pthread_mutex_lock(&mtx);
//		if (s != 0)
//			exit(EXIT_FAILURE);
//		loc = glob;
//		++loc;
//        glob = loc;
//		s = pthread_mutex_unlock(&mtx);
//		if (s != 0)
//			exit(EXIT_FAILURE);
//	}
//	return NULL;
//}


void print_t_philo(t_philo philo)
{
	printf("%lld, %lld, %lld, %lld, %lld\n", philo.number_of_philosophers,
		   philo.time_to_die, philo.time_to_eat, philo.time_to_sleep,
		   philo.number_of_times_each_philosopher_must_eat);
}

int	main(int argc, char *argv[])
{
	t_philo philo;

	if (!is_right_arg(argc, argv))
		return (0);
	philo = input_args(argc, argv);
	print_t_philo(philo);
	return (0);
}
