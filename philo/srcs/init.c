/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:31:31 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/28 19:04:25 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	set_params(data, av);
	if (!init_philo(data))
		return (0);
	if (!init_forks(data))
		return (0);
	return (1);
}

int	set_params(t_data *data, char **av)
{
	data->philo_nb = ft_atoi(av[0]);
	data->t_die = ft_atoi(av[1]);
	data->t_eat = ft_atoi(av[2]);
	data->t_sleep = ft_atoi(av[3]);
	if (av[4])
		data->meals_nb = ft_atoi(av[4]);
	else
		data->meals_nb = -1;
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	// ALLOC
	data->philos = malloc(sizeof(t_philo) * data->philo_nb);
	if (!data->philos)
		return (error_handler(4), 0);
	memset(data->philos, 0, sizeof(t_philo) * data->philo_nb);
	//ALLOC
	data->tid = malloc(sizeof(pthread_t) * data->philo_nb);
	if (!data->tid)
		return (free_data(data), error_handler(4), 0);
	// ALLOC
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!data->forks)
		return (free_data(data), error_handler(4), 0);
	i = 0;
	// PHILO + MUTEX INIT 
	while (i < data->philo_nb)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].t_die = data->t_die;
		if (pthread_mutex_init(&data->philos[i].lock, NULL) != 0)
			return (error_handler(5), err_mutex_init(data, i, 1), 0);
		i++;
	}
	return (1);
}

int	init_forks(t_data *data)
{
	int	i;

	//MUTEX INIT
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		return (err_mutex_init(data, 0, 2), error_handler(5), 0);
	//MUTEX INIT
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (err_mutex_init(data, 0, 3), error_handler(5), 0);
	i = -1;
	//MUTEX INIT
	while (++i < data->philo_nb)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (err_mutex_init(data, i, 4), error_handler(5), 0);
	}
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_nb - 1];
	i = 1;
	while (i < data->philo_nb)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (1);
}
