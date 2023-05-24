/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:23:18 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/24 23:31:08 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>
# include <stdint.h>
# include <string.h>
# define ERR_NB_ARGS_CD 1
# define ERR_NB_ARGS_MG "Invalid number of arguments (4 or 5).\n"
# define ERR_NB_PH_CD 2
# define ERR_NB_PH_MG "Invalid number of philisoph.\n"
# define ERR_B_ZERO_CD 3
# define ERR_B_ZERO_MG "Arguments values should be greater than zero.\n"
# define ERR_ALLOC_CD 4
# define ERR_ALLOC_MG "Cannot allocate memory.\n"
# define ERR_MUTEX_CD 5
# define ERR_MUTEX_MG "Error initializing mutex.\n"

struct	s_data;

typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			t1;
	int					id;
	int					eat_cont;
	int					status;
	int					eating;
	int					t_die;
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
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					t_start;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		write;
}				t_data;

/*parsing.c*/
int		check_args_num(int argc);
int		check_args(char **av, int ac);
/*ft.c*/
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
/*init.c*/
int		init(t_data *data, char **av);
int		set_params(t_data *data, char **av);
int		init_philo(t_data *data);
int		init_forks(t_data *data);
/*error.c*/
void	error_handler(int errcode);
void	err_mutex_init(t_data *data, int failure, int code);
/*free.c*/
void	free_data(t_data *data);
/*routine.c*/
void	*routine(void *args);
#endif