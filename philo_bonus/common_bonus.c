/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:55:17 by salee2            #+#    #+#             */
/*   Updated: 2022/12/05 19:55:17 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_common_philo(int argc, char *argv[], t_common_philo *common)
{
	if (!is_right_arg(argc, argv))
		return (EXIT_FAILURE);
	*common = input_args(argc, argv);
	common->base_usec = get_usec();
	return (EXIT_SUCCESS);
}
