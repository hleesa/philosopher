/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:41:42 by salee2            #+#    #+#             */
/*   Updated: 2023/01/21 15:41:43 by salee2           ###   ########.fr       */
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

void	init_semaphores(t_sem_name *sem_name, t_ll num_of_fork)
{
	int	i;

	i = -1;
	while (++i < num_of_fork)
	{
		init_semaphore(sem_name->last_eat_sem_names[i], 1);
		init_semaphore(sem_name->num_of_eat_sem_names[i], 1);
	}
	init_semaphore("/forks", num_of_fork);
	init_semaphore("/print", 1);
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

void	create_semaphores(t_sem_name *sem_name, t_ll num_of_fork)
{
	int	i;

	i = -1;
	while (++i < num_of_fork)
	{
		create_semaphore(sem_name->last_eat_sem_names[i], 1);
		create_semaphore(sem_name->num_of_eat_sem_names[i], 1);
	}
	create_semaphore("/forks", num_of_fork);
	create_semaphore("/print", 1);
	return ;
}

void	delete_semaphores(t_sem_name *sem_name, t_ll num_of_fork)
{
	int	i;

	i = -1;
	while (++i < num_of_fork)
	{
		semaphore_unlink(sem_name->last_eat_sem_names[i]);
		semaphore_unlink(sem_name->num_of_eat_sem_names[i]);
	}
	semaphore_unlink("/forks");
	semaphore_unlink("/print");
	return ;
}
