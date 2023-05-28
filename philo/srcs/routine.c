/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:17:41 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/28 18:38:32 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *args)
{
	(void) args;
	return (NULL);
}

int	philos(t_data *data)
{
	int			i;
	pthread_t	t1;

	data->t_start = get_time();
	if (!data->t_start)
		return (error_handler(8), err_mutex_init(data, data->philo_nb, 4), 0);
	i = -1;
	if (data->meals_nb > 0)
	{
		pthread_create(&t1, NULL, &monitor, &data->philos[0])
	}
	while (++i < data->philo_nb)
	{
		if (pthread_create(&t1, NULL, &routine, &data->philos[0]) != 0)
			return (error_handler(6), err_mutex_init(data, data->philo_nb, 4), 0);
	}
}
