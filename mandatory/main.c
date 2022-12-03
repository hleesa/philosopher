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

static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *
threadFunc(void *arg)
{
	int loops = *((int *) arg);
	int loc, j, s;

	for (j = 0; j < loops; ++j)
	{
		s = pthread_mutex_lock(&mtx);
		if (s != 0)
			exit(EXIT_FAILURE);
		loc = glob;
		++loc;
        glob = loc;
		s = pthread_mutex_unlock(&mtx);
		if (s != 0)
			exit(EXIT_FAILURE);
	}
	return NULL;
}


int main(int argc, char * argv[])
{
	pthread_t t1, t2;
	int loops, s;

	(void) argv;
	(void) argc;


	loops = ft_atoll(argv[1]);

	s = pthread_create(&t1, NULL, threadFunc, &loops);
	if (s != 0)
		exit(EXIT_FAILURE);
	s = pthread_create(&t2, NULL, threadFunc, &loops);
	if (s != 0)
		exit(EXIT_FAILURE);

	s = pthread_join(t1, NULL);
	if (s != 0)
		exit(0);
	s = pthread_join(t2, NULL);
	if(s !=0)
		exit(0);

	printf("glob = %d\n", glob);

	return (0);
}
