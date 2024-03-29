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

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>

typedef int			t_bool;
typedef long long	t_ll;

enum e_arg
{
	MANDA = 5,
	OPTION = 6
};

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

typedef struct s_common_philo
{
	t_ll			number_of_philosophers;
	t_ll			time_to_die;
	t_ll			time_to_eat;
	t_ll			time_to_sleep;
	t_ll			number_of_times_each_philosopher_must_eat;
	t_ll			base_usec;
	t_bool			is_end;
	pthread_mutex_t	end_mtx;
	pthread_mutex_t	*fork_mtx;
}	t_common_philo;

typedef struct s_philo
{
	int				nth_philo;
	int				left_fork;
	int				right_fork;
	int				num_of_eat;
	t_ll			last_eat_usec;
	t_ll			error_usec;
	pthread_t		tid;
	pthread_mutex_t	last_eat_mtx;
	pthread_mutex_t	num_of_eat_mtx;
	t_common_philo	*common;
}	t_philo;

t_bool			is_right_arg(int argc, char *argv[]);
t_common_philo	input_args(int argc, char *argv[]);
int				init_common_philo(int argc, char *argv[], \
t_common_philo *common);
long long		ft_atoll(const char *str);
void			*life_of_philo(void *arg);
int				malloc_philo_thread(t_philo **philo, int size);
int				init_philo_thread(t_philo *philo, t_common_philo *common);
int				create_philo_thread(t_philo *philo, t_common_philo *common);
int				join_philo_thread(t_philo *philo, int i_end);
int				print_state(t_philo *philo, t_common_philo *common, \
enum e_tstate state);
int				life_of_watcher(t_philo *philo, t_common_philo *common);
int				create_thread(t_common_philo *common);
void			my_usleep(t_ll usec);
t_ll			get_usec(void);

#endif //PHILO_H
