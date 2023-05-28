/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:34:50 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/29 01:13:02 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		think(philo);
		eat(philo);
		if (check_death(philo))
		{
			print_status(philo, "has died");
			return (NULL);
		}
		sleep_time(philo);
		if (philo->data->meals_nb != -1 && check_meal_count(philo->data))
			return (NULL);
	}
	return (NULL);
}

int	init_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_create(&data->philos[i].t1,
				NULL, &philosopher_routine, &data->philos[i]) != 0)
		{
			perror("Failed to create thread");
			return (1);
		}
		ft_usleep(100);
	}
	while (i--)
	{
		if (pthread_join(data->philos[i].t1, NULL) != 0)
		{
			perror("Failed to join thread");
			return (1);
		}
	}
	return (0);
}
