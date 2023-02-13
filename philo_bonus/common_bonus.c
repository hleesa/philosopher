/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:24:56 by salee2            #+#    #+#             */
/*   Updated: 2023/01/07 18:24:58 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_common_philo(int argc, char *argv[], t_common_philo *common)
{
	if (!is_right_arg(argc, argv))
	{
		printf("error: init_common_philo\n");
		exit(EXIT_FAILURE);
	}
	*common = input_args(argc, argv);
	if (common->number_of_philosophers < 0)
		exit(EXIT_FAILURE);
	common->base_usec = get_usec();
	return ;
}
