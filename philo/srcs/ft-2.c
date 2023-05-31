/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:27:44 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/31 13:09:22 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	case_one(t_phi *phi)
{
	pthread_mutex_lock(phi->l_fork);
	print_status(phi->data, phi->id, "has taken a fork");
	pthread_mutex_unlock(phi->l_fork);
}

int	check_died(t_phi *philo)
{
	pthread_mutex_lock(&(philo->data->m_eat));
	if (philo->data->died)
		return (pthread_mutex_unlock(&(philo->data->m_eat)), 1);
	pthread_mutex_unlock(&(philo->data->m_eat));
	return (0);
}

void	define_died(t_data *data, int i)
{
	pthread_mutex_lock(&(data->m_eat));
	if (get_time() - data->philos[i].last_meal > data->t_die)
	{
		pthread_mutex_unlock(&(data->m_eat));
		print_status(data, data->philos[i].id, "died");
		pthread_mutex_lock(&(data->m_eat));
		data->died = 1;
	}
	pthread_mutex_unlock(&(data->m_eat));
}

int	check_eat(t_phi *philo)
{
	pthread_mutex_lock(&(philo->data->m_eat));
	if (philo->data->finished)
		return (pthread_mutex_unlock(&(philo->data->m_eat)), 1);
	pthread_mutex_unlock(&(philo->data->m_eat));
	return (0);
}
