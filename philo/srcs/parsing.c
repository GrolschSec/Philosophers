/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:14:37 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/31 14:13:22 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_args_num(int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	error_msg(P_ERR_NB_ARG);
	return (0);
}

int	check_args(char **av, int ac)
{
	int	i;
	int	arg;

	i = 0;
	while (i < ac)
	{
		arg = ft_atoi(av[i]);
		if (i == 0 && arg < 1)
			return (error_msg(P_ERR_ARG), 0);
		else if ((ac == 5 && i == 4) && arg < 1)
			return (error_msg(P_ERR_ARG), 0);
		else if (arg < 0)
			return (error_msg(P_ERR_ARG), 0);
		i++;
	}
	return (1);
}
