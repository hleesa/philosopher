/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:17:49 by salee2            #+#    #+#             */
/*   Updated: 2022/11/29 15:17:53 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PHILO_H
#define PHILO_PHILO_H

#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

typedef int t_bool;
typedef unsigned long long ull;

typedef struct s_philo
{
	ull	number_of_philosophers;
	ull	time_to_die;
	ull	time_to_eat;
	ull	time_to_sleep;
	ull	number_of_times_each_philosopher_must_eat;
}	t_philo;

enum e_philo_state
{
	THINK,
	FORK,
	EAT,
	SLEEP,
	DIE
};

enum e_bool
{
	FALSE,
	TRUE
};

long long	ft_atoll(const char *str);

#endif //PHILO_PHILO_H
