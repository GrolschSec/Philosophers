/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:35:08 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/29 01:14:36 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
	}
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		print_status(philo, "has dropped a fork");
		pthread_mutex_unlock(philo->r_fork);
		print_status(philo, "has dropped a fork");
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		print_status(philo, "has dropped a fork");
		pthread_mutex_unlock(philo->l_fork);
		print_status(philo, "has dropped a fork");
	}
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void	sleep_time(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->t_sleep);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	print_status(philo, "is eating");
	philo->last_meal = get_time();
	ft_usleep(philo->data->t_eat);
	drop_forks(philo);
}

int	check_death(t_philo *philo)
{
	u_int64_t	current_time;

	current_time = get_time();
	if ((current_time - philo->last_meal) > philo->data->t_die)
		return (1);
	return (0);
}

int	check_meal_count(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
	{
		if (data->philos[i].eat_cont < data->meals_nb)
			return (0);
	}
	return (0);
}
