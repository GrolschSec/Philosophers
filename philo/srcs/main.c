/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:11:50 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/31 14:04:23 by rlouvrie         ###   ########.fr       */
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
	if (!init_threads(&data))
		return (4);
	return (0);
}
