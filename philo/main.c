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

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_common_philo	common;

	if (init_common_philo(argc, argv, &common))
		return (EXIT_FAILURE);
	if (create_thread(&common))
		return (EXIT_FAILURE);
	return (0);
}
