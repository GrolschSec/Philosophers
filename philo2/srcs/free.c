/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:54:00 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/28 19:24:40 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_data(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
}

void	mutexes_destroy(t_data *data, int failure, int code)
{
	int	i;

	if (code == 4)
	{
		i = -1;
		while (++i < failure)
			pthread_mutex_destroy(&data->forks[i]);
	}
	if (code == 3 || code == 4)
		pthread_mutex_destroy(&data->write);
	if (code == 2 || code == 3 || code == 4)
		pthread_mutex_destroy(&data->lock);
	if (code == 1 || code == 2 || code == 3 || code == 4)
	{
		i = -1;
		if (code > 1)
			failure = data->philo_nb;
		while (++i < failure)
		{
			pthread_mutex_destroy(&data->philos[i].lock);
		}
	}
	free_data(data);
}
