/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:00:19 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/25 00:09:12 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error_handler(int errcode)
{
	char	*msg;

	if (errcode == ERR_NB_ARGS_CD)
		msg = ERR_NB_ARGS_MG;
	else if (errcode == ERR_NB_PH_CD)
		msg = ERR_NB_PH_MG;
	else if (errcode == ERR_B_ZERO_CD)
		msg = ERR_B_ZERO_MG;
	else if (errcode == ERR_ALLOC_CD)
		msg = ERR_ALLOC_MG;
	printf("Error: %s", msg);
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
