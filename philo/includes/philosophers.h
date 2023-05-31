/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:23:18 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/31 13:32:52 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# define P_ERR_NB_ARG 1
# define P_ERR_ARG 2
# define I_ERR_MEM 3
# define I_ERR_MUTEX 4

struct	s_data;

typedef struct s_phi
{
	int				id;
	int				eat_count;
	long long		last_meal;
	pthread_t		th;
	struct s_data	*data;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}				t_phi;

typedef struct s_data
{
	int				died;
	int				finished;
	int				nb_phi;
	int				nb_meals;
	int				t_eat;
	int				t_sleep;
	int				t_die;
	long long		t_start;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_write;
	pthread_mutex_t	*forks;
	t_phi			*philos;
}				t_data;

/*ft.c*/
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
long long	get_time(void);
void		ft_usleep(long long time, t_data *data);
void		print_status(t_data *data, int id, char *str);
/*ft-2.c*/
void		case_one(t_phi *phi);
int			check_died(t_phi *philo);
void		define_died(t_data *data, int i);
int			check_eat(t_phi *philo);
/*init.c*/
int			init(t_data *data, char **av);
void		set_params(t_data *data, char **av);
int			alloc(t_data *data);
int			init_mutex(t_data *data);
void		init_philos(t_data *data);
/*threads.c*/
void		*routine(void *philo);
void		eating(t_phi *philo);
void		end_checker(t_data *data);
int			init_threads(t_data *data);
/*error.c*/
void		write_error(char *str);
void		error_msg(int errcode);
/*free.c*/
void		free_mem(t_data *data);
void		destroy_mutex(t_data *data, int code, int failure);
void		clear_all(t_data *data);
/*parsing.c*/
int			check_args_num(int argc);
int			check_args(char **av, int ac);
#endif