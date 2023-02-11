/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:31:12 by salee2            #+#    #+#             */
/*   Updated: 2023/02/11 14:31:13 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphore(char *name, int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0660, value);
	if (sem == SEM_FAILED)
		semaphore_unlink(name);
	return ;
}

void	init_semaphores(t_ll num_of_fork)
{
	init_semaphore("/forks", num_of_fork);
	init_semaphore("/print", 1);
	init_semaphore("/last_eat", 1);
	init_semaphore("/num_of_eat", 1);
	return ;
}

void	create_semaphore(char *name, int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT, 0660, value);
	if (sem == SEM_FAILED)
	{
		printf("error: create_semaphore\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	create_semaphores(t_ll num_of_fork)
{
	create_semaphore("/forks", num_of_fork);
	create_semaphore("/print", 1);
	create_semaphore("/last_eat", 1);
	create_semaphore("/num_of_eat", 1);
	return ;
}

void	delete_semaphores(void)
{
	semaphore_unlink("/forks");
	semaphore_unlink("/print");
	semaphore_unlink("/last_eat");
	semaphore_unlink("/num_of_eat");
	return ;
}
