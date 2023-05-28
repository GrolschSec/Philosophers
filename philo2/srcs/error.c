/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:54:20 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/28 19:08:01 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error_msg(int errcode)
{
	if (errcode == 1)
		printf("Error: Invalid number of arguments (4 or 5).\n");
	else if (errcode == 2)
		printf("Error: Invalid number of philisophers.\n");
	else if (errcode == 3)
		printf("Error: Arguments values should be greater than zero.\n");
	else if (errcode == 4)
		printf("Error: Cannot allocate memory.\n");
	else if (errcode == 5)
		printf("Error: Cannot initialize mutexes.\n");
	else if (errcode == 6)
		printf("Error: Cannot create threads\n");
	else if (errcode == 7)
		printf("Error: Cannot join threads\n");
	else if (errcode == 8)
		printf("Error: Cannot get time.\n");
}
