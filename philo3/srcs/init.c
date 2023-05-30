/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:13:43 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/30 22:12:29 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	set_params(data, av);
	if (!alloc(data))
		return (0);
	if (!init_mutex(data))
		return (0);
	init_philos(data);
	return (1);
}

void	set_params(t_data *data, char **av)
{
	data->nb_phi = ft_atoi(av[0]);
	data->t_die = ft_atoi(av[1]);
	data->t_eat = ft_atoi(av[2]);
	data->t_sleep = ft_atoi(av[3]);
	if (av[4])
		data->nb_meals = ft_atoi(av[4]);
	else
		data->nb_meals = -1;
}

int	alloc(t_data *data)
{
	data->philos = malloc(sizeof(t_phi) * data->nb_phi);
	if (!data->philos)
		return (error_msg(I_ERR_MEM), 0);
	memset(data->philos, 0, sizeof(t_phi) * data->nb_phi);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_phi);
	if (!data->forks)
		return (error_msg(I_ERR_MEM), free_mem(data), 0);
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&(data->m_eat), NULL) != 0)
		return (error_msg(I_ERR_MUTEX), free_mem(data), 0);
	if (pthread_mutex_init(&(data->m_write), NULL) != 0)
		return (error_msg(I_ERR_MUTEX), destroy_mutex(data, 1, 0), 0);
	i = -1;
	while (++i < data->nb_phi)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (error_msg(I_ERR_MUTEX), destroy_mutex(data, 2, i), 0);
	}
	return (1);
}

void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_phi)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
	}
	data->philos[0].l_fork = &data->forks[data->nb_phi - 1];
	data->philos[0].r_fork = &data->forks[0];
	i = 0;
	while (++i < data->nb_phi)
	{
		data->philos[i].l_fork = &data->forks[i - 1];
		data->philos[i].r_fork = &data->forks[i];
	}
}
