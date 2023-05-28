/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:00:19 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/28 18:26:45 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error_handler(int errcode)
{
	if (errcode == 1)
		printf("Error: Invalid number of arguments (4 or 5).\n");
	else if (errcode == 2)
		printf("Error: Invalid number of philisophers.\n");
	else if (errcode == 3)
		printf("Error: Arguments values should be greater than zero.\n");
	else if (errcode == 4)
		printf("Error: Cannot allocate memory.\n");
	else if (errcode == 5)
		printf("Error: Cannot initialize mutexes.\n");
	else if (errcode == 6)
		printf("Error: Cannot create threads\n");
	else if (errcode == 7)
		printf("Error: Cannot join threads\n");
	else if (errcode == 8)
		printf("Error: Cannot get time.\n");
}

void	err_mutex_init(t_data *data, int failure, int code)
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
