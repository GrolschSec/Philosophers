/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:11:50 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/30 22:24:11 by rlouvrie         ###   ########.fr       */
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
	destroy_mutex(&data, 2, data.nb_phi);
	return (0);
}
