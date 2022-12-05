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
#include <stdlib.h>
#include <pthread.h>

typedef int t_bool;
typedef long long ll;

enum e_bool
{
	FALSE,
	TRUE
};

enum e_tstate
{
	THINK,
	FORK,
	EAT,
	SLEEP,
	DIE
};

typedef struct s_common
{
	ll	number_of_philosophers;
	ll	time_to_die;
	ll	time_to_eat;
	ll	time_to_sleep;
	ll	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t *chopstick_mtx;
	struct timeval base_time;
}	t_common;

typedef struct s_thread
{
	pthread_t tid;
	int nth_philo;
	enum e_tstate state;
	t_common *common_data;
}	t_thread;


long long	ft_atoll(const char *str);
t_bool	is_right_arg(int argc, char *argv[]);
t_common	input_args(int argc, char *argv[]);
int	init_common_data(int argc, char *argv[], t_common *common_data);
void print_state(t_thread *philo);
int init_philo_thread(t_thread *philo, t_common *common_data);
void *thread_func(void *arg);


#endif //PHILO_PHILO_H
