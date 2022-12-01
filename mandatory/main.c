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

static pthread_cond_t threadDied = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t threadMutex = PTHREAD_MUTEX_INITIALIZER;

static int totThreads = 0;
static int numLive = 0;

static int numUnjoined = 0;

enum tsate{
	TS_ALIVE,
	TS_TERMINATED,
	TS_JOINED
};

static 	struct {
	pthread_t tid;
	enum tsate state;
	int sleepTime;
} *thread;

static void *
threadFunc(void *arg)
{
	long idx = (long) arg;
	int s;

	sleep(thread[idx].sleepTime);
	printf("Thread %ld terminating\n", idx);

	s = pthread_mutex_lock(&threadMutex);
	if (s != 0)
		exit(EXIT_FAILURE);

	numUnjoined++;
	thread[idx].state = TS_TERMINATED;

	s = pthread_mutex_unlock(&threadMutex);
	if (s != 0)
		exit(EXIT_FAILURE);
	s = pthread_cond_signal(&threadDied);

	return NULL;
}

int main(int argc, char * argv[])
{
	long s, idx;

	(void) argv;
	(void) argc;

	thread = calloc(argc - 1, sizeof(*thread));
	if (thread == NULL)
		exit(EXIT_FAILURE);

	for (idx = 0; idx < argc - 1; ++idx)
	{
		thread[idx].sleepTime = atoi(argv[idx + 1]);
		thread[idx].state = TS_ALIVE;
		s = pthread_create(&thread[idx].tid, NULL, threadFunc, (void *)idx);
		if(s!=0)
			exit(EXIT_FAILURE);
	}

	totThreads = argc - 1;
	numLive = totThreads;

	while (numLive > 0)
	{
		s = pthread_mutex_lock(&threadMutex);
		if (s!=0)
			exit(EXIT_FAILURE);
	}

	while(numUnjoined == 0)
	{
		s = pthread_cond_wait(&threadDied, &threadMutex);
		if (s != 0)
			exit(EXIT_FAILURE);
	}

	for (idx = 0; idx < totThreads; ++idx)
	{
		if (thread[idx].state == TS_TERMINATED)
		{
			s = pthread_join(thread[idx].tid, NULL);
			if(s!=0)
				exit(EXIT_FAILURE);

			thread[idx].state = TS_JOINED;
			numLive--;
			numUnjoined--;

			printf("Reaped thead %ld (numLive=%d)\n", idx, numLive);
		}
	}

	s = pthread_mutex_unlock(&threadMutex);
	if(s!=0)
		exit(EXIT_FAILURE);

	return (0);
}
