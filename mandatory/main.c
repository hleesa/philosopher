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

static void *
threadFunc(void *arg)
{
	char *s = (char *) arg;
	printf("%s", s);
	return (void *) strlen(s);
}

int main(int argc, char * argv[])
{
	pthread_t t1;
	void *res;
	int s;
	(void) argv;
	(void) argc;

	s = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
	if (s != 0)
	{
		printf("error");
		exit(0);
	}

	printf("Message from Main()\n");
	s = pthread_join(t1, &res);
	if (s != 0)
	{
		printf("error");
		exit(0);
	}
	printf("Thread returned %ld\n", (long) res);

	printf("%llmax:%lld\n", LLONG_MAX);
	printf("%llmin:%lld\n", LLONG_MIN);
	printf("atoll:%lld\n",atoll(argv[1]));
	printf("ft_atoll:%lld\n", ft_atoll(argv[1]));


	exit(EXIT_SUCCESS);
}
