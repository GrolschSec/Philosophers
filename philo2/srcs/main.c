/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:28:00 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/29 01:07:51 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args_num(argc))
		return (1);
	if (!check_args(&argv[1], argc - 1))
		return (2);
	if (!init(&data, &argv[1]))
		return (3);
	init_threads(&data);
	clear(&data);
	return (0);
}