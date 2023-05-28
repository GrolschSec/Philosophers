/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:36:02 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/29 01:11:18 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_status(t_philo *philo, char *message)
{
	u_int64_t	timestamp;

	pthread_mutex_lock(&philo->data->write);
	timestamp = get_time() - philo->data->t_start;
	printf("[%lu] %d %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(&philo->data->write);
}
