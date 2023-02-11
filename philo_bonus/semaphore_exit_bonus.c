/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:48:04 by salee2            #+#    #+#             */
/*   Updated: 2023/01/24 19:48:05 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	semaphore_unlink(const char *name)
{
	if (sem_unlink(name) == ERROR)
	{
		printf("error: semaphore_unlink\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	semaphore_wait(sem_t *sem)
{
	if (sem_wait(sem) == ERROR)
	{
		printf("error: semaphore_wait\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	semaphore_post(sem_t *sem)
{
	if (sem_post(sem) == ERROR)
	{
		printf("error: semaphore_post\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

sem_t	*semaphore_get(const char *name)
{
	sem_t	*sem;

	sem = sem_open(name, 0);
	if (sem == SEM_FAILED)
	{
		printf("error: semaphore_get\n");
		exit(EXIT_FAILURE);
	}
	return (sem);
}
