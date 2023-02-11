/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:25:43 by salee2            #+#    #+#             */
/*   Updated: 2023/01/07 18:25:45 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

typedef int			t_bool;
typedef long long	t_ll;

enum e_arg
{
	ERROR = -1,
	MANDA = 5,
	OPTION = 6
};

enum e_bool
{
	FALSE,
	TRUE
};

enum e_process
{
	CHILD,
	PARENT
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
	t_ll	number_of_philosophers;
	t_ll	time_to_die;
	t_ll	time_to_eat;
	t_ll	time_to_sleep;
	t_ll	number_of_times_each_philosopher_must_eat;
	t_ll	base_usec;
}	t_common_philo;

typedef struct s_philo
{
	int				nth_philo;
	int				num_of_eat;
	t_ll			last_eat_usec;
	t_ll			error_usec;
	pthread_t		tid;
	t_common_philo	*common;
}	t_philo;

typedef struct s_sems
{
	sem_t	*forks;
	sem_t	*print;
	sem_t	*last_eat;
	sem_t	*num_of_eat;
}	t_sems;

t_bool			is_right_arg(int argc, char *argv[]);
t_common_philo	input_args(int argc, char *argv[]);
void			init_common_philo(int argc, char *argv[], \
t_common_philo *common);
void			exit_if_fork_error(pid_t pid);
long long		ft_atoll(const char *str);
char			*ft_itoa(int n);
void			life_of_philo(t_philo *philo, t_common_philo *common);
void			create_philo(t_philo *philo, t_common_philo *common, \
pid_t **pids);
void			kill_philo(pid_t *pids, int num_of_philo);
void			print_state(t_philo *philo, t_common_philo *common, \
enum e_tstate state, sem_t *print);
void			init_semaphores(t_ll num_of_fork);
void			create_semaphores(t_ll num_of_fork);
void			delete_semaphores(void);
void			semaphore_unlink(const char *name);
void			semaphore_wait(sem_t *sem);
void			semaphore_post(sem_t *sem);
sem_t			*semaphore_get(const char *name);
void			my_usleep(t_ll usec);
t_ll			get_usec(void);
void			*life_of_watcher(void *arg);

#endif //PHILO_BONUS_H
