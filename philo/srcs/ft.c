/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:51:29 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/31 13:44:26 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			tmp;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	tmp = (int)result;
	if (str[i] || result != tmp || result < 0)
		return (-1);
	return (tmp);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long long time, t_data *data)
{
	long long	temp;

	temp = get_time();
	while (!(check_died(&data->philos[0])))
	{
		if (get_time() - temp >= time)
			break ;
		usleep(50);
	}
}

void	print_status(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->m_write));
	if (!(check_died(&data->philos[0])))
	{
		printf("%lli ", get_time() - data->t_start);
		printf("%d %s\n", id, str);
	}
	pthread_mutex_unlock(&(data->m_write));
}
