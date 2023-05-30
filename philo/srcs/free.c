/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:20:00 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/30 22:45:52 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_mem(t_data *data)
{
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
	if (data->forks)
	{
		free(data->forks);
		data->philos = NULL;
	}
}

void	destroy_mutex(t_data *data, int code, int failure)
{
	int	i;

	if (code == 2)
	{
		i = -1;
		while (++i < failure)
			pthread_mutex_destroy(&(data->forks[i]));
	}
	if (code == 2 || code == 1)
	{
		pthread_mutex_destroy(&(data->m_write));
		pthread_mutex_destroy(&(data->m_eat));
	}
	free_mem(data);
}

void	clear_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_phi)
		pthread_join(data->philos[i].th, NULL);
	destroy_mutex(data, 2, data->nb_phi);
}
