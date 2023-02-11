/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_name_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:24:12 by salee2            #+#    #+#             */
/*   Updated: 2023/02/04 16:24:15 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sem_names(t_sem_name *sem_name, int num_of_philo)
{
	sem_name->last_eat_sem_names = malloc(sizeof(char *) * num_of_philo);
	if (sem_name->last_eat_sem_names == NULL)
	{
		printf("error: init_sem_names\n");
		exit(EXIT_FAILURE);
	}
	sem_name->num_of_eat_sem_names = malloc(sizeof(char *) * num_of_philo);
	if (sem_name->num_of_eat_sem_names == NULL)
	{
		printf("error: init_sem_names\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	create_sem_name(char **name, int offset, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		name[i] = ft_itoa(offset + i);
		if (name[i] == NULL)
		{
			printf("error: create_sem_name");
			exit(EXIT_FAILURE);
		}
	}
	return ;
}

void	create_sem_names(t_sem_name *sem_name, int num_of_philo)
{
	create_sem_name(sem_name->last_eat_sem_names, LAST_EAT, num_of_philo);
	create_sem_name(sem_name->num_of_eat_sem_names, NUM_OF_EAT, num_of_philo);
	return ;
}

void	free_sem_name(t_sem_name *sem_name, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free(sem_name->last_eat_sem_names[i]);
		free(sem_name->num_of_eat_sem_names[i]);
	}
}
