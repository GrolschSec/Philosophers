/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:23:18 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/29 01:07:00 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

struct	s_data;

typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			t1;
	int					id;
	int					eat_cont;
	int					status;
	int					eating;
	u_int64_t			last_meal;
	u_int64_t			t_die;
	pthread_mutex_t		lock;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
}				t_philo;

typedef struct s_data
{
	pthread_t			*tid;
	int					philo_nb;
	int					meals_nb;
	int					dead;
	int					finished;
	t_philo				*philos;
	u_int64_t			t_die;
	u_int64_t			t_eat;
	u_int64_t			t_sleep;
	u_int64_t			t_start;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		write;
}				t_data;

/*parsing.c*/
int			check_args_num(int argc);
int			check_args(char **av, int ac);
/*ft.c*/
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
u_int64_t	get_time(void);
void		ft_usleep(useconds_t time);
/*init.c*/
int			init(t_data *data, char **av);
int			set_params(t_data *data, char **av);
int			alloc(t_data *data);
int			init_mutexes(t_data *data);
int			init_philos(t_data *data);
/*free.c*/
void		free_data(t_data *data);
void		mutexes_destroy(t_data *data, int failure, int code);
void		threads_join(t_data *data);
void		clear(t_data *data);
/*error.c*/
void		error_msg(int errcode);
/*actions.c*/
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		think(t_philo *philo);
void		sleep_time(t_philo *philo);
void		eat(t_philo *philo);
/*threads.c*/
int			init_threads(t_data *data);
void		*philosopher_routine(void *arg);
/*print.c*/
void		print_status(t_philo *philo, char *message);
/*??*/
int			check_death(t_philo *philo);
int			check_meal_count(t_data *data);
#endif