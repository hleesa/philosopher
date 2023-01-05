/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:32:46 by salee2            #+#    #+#             */
/*   Updated: 2022/12/08 17:32:47 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_thread(t_philo *philo, t_common_philo *common)
{
	if (create_philo_thread(philo, common))
		return (EXIT_FAILURE);
	if (life_of_watcher(philo, common))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
