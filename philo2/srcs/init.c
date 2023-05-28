/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:53:40 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/28 19:36:03 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	set_params(data, av);
	if (!alloc(data))
		return (0);
	if (!init_mutexes(data))
		return (0);
	init_philos(data);
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

int	alloc(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->philo_nb);
	if (!data->philos)
		return (error_msg(4), 0);
	memset(data->philos, 0, sizeof(t_philo) * data->philo_nb);
	data->tid = malloc(sizeof(pthread_t) * data->philo_nb);
	if (!data->tid)
		return (free_data(data), error_msg(4), 0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!data->forks)
		return (free_data(data), error_msg(4), 0);
	return (1);
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_mutex_init(&data->philos[i].lock, NULL) != 0)
			return (mutexes_destroy(data, i, 1), error_msg(5), 0);
	}
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		return (mutexes_destroy(data, 0, 2), error_msg(5), 0);
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (mutexes_destroy(data, 0, 3), error_msg(5), 0);
	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (mutexes_destroy(data, i, 4), error_msg(5), 0);
	}
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_nb - 1];
	i = -1;
	while (++i < data->philo_nb)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].t_die = data->t_die;
	}
	i = 1;
	while (i < data->philo_nb)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (1);
}
