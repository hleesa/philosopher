/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:33:24 by salee2            #+#    #+#             */
/*   Updated: 2023/01/24 20:33:25 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philo(t_philo *philo, t_common_philo *common, pid_t **pids)
{
	int			i;
	pthread_t	tid;

	i = -1;
	philo->common = common;
	while (++i < common->number_of_philosophers)
	{
		(*pids)[i] = fork();
		exit_if_fork_error((*pids)[i]);
		if ((*pids)[i] == CHILD)
		{
			philo->nth_philo = i + 1;
			philo->num_of_eat = 0;
			philo->last_eat_usec = get_usec();
			philo->error_usec = 0LL;
			pthread_create(&tid, NULL, life_of_watcher, philo);
			pthread_detach(tid);
			life_of_philo(philo, common);
			sleep(11);
		}
	}
}

void	kill_philo(pid_t *pids, int num_of_philo)
{
	int	i;

	i = -1;
	while (++i < num_of_philo)
		kill(pids[i], SIGTERM);
	return ;
}
