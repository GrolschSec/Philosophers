/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:42:23 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/24 23:01:45 by rlouvrie         ###   ########.fr       */
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
