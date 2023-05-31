/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:40:56 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/31 13:08:17 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *philo)
{
	t_phi	*phi;
	int		i;

	i = 0;
	phi = (t_phi *)philo;
	if (phi->data->nb_phi == 1)
		return (case_one(phi), NULL);
	if (phi->id % 2)
		usleep(15000);
	while (!(check_died(phi)))
	{
		eating(phi);
		if (check_eat(phi))
			break ;
		print_status(phi->data, phi->id, "is sleeping");
		ft_usleep(phi->data->t_sleep, phi->data);
		print_status(phi->data, phi->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	eating(t_phi *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_status(philo->data, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo->data, philo->id, "has taken a fork");
	}
	print_status(philo->data, philo->id, "is eating");
	pthread_mutex_lock(&(philo->data->m_eat));
	philo->last_meal = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->data->m_eat));
	ft_usleep(philo->data->t_eat, philo->data);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	end_checker(t_data *data)
{
	int	i;

	while (!(data->finished))
	{
		i = -1;
		while (++i < data->nb_phi && !(data->died))
		{
			define_died(data, i);
		}
		if (data->died)
			break ;
		i = 0;
		pthread_mutex_lock(&data->m_eat);
		while (data->nb_meals != -1 && i < data->nb_phi
			&& data->philos[i].eat_count >= data->nb_meals)
			i++;
		if (i == data->nb_phi)
			data->finished = 1;
		pthread_mutex_unlock(&data->m_eat);
	}
}

int	init_threads(t_data *data)
{
	int		i;
	t_phi	*philos;

	philos = data->philos;
	data->t_start = get_time();
	i = -1;
	while (++i < data->nb_phi)
	{
		if (pthread_create(&(philos[i].th), NULL, &routine, &philos[i]) != 0)
			return (0);
		pthread_mutex_lock(&(data->m_eat));
		philos[i].last_meal = get_time();
		pthread_mutex_unlock(&(data->m_eat));
	}
	end_checker(data);
	clear_all(data);
	return (1);
}
