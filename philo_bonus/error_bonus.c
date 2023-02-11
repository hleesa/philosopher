/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:42:21 by salee2            #+#    #+#             */
/*   Updated: 2023/01/03 14:42:21 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_if_fork_error(pid_t pid)
{
	if (pid == ERROR)
	{
		printf("fork error\n");
		exit(EXIT_FAILURE);
	}
	return ;
}
