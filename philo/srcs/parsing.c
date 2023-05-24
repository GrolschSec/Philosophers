/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:32:59 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/24 21:11:37 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_args_num(int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	error_handler(ERR_NB_ARGS_CD);
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
			return (error_handler(ERR_NB_PH_CD), 0);
		else if (arg < 1)
			return (error_handler(ERR_B_ZERO_CD), 0);
		i++;
	}
	return (1);
}
