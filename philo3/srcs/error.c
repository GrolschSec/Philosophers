/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:50:53 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/05/30 22:18:27 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	write_error(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
}

void	error_msg(int errcode)
{
	if (errcode == P_ERR_ARG)
		write_error("Wrong arguments.");
	else if (errcode == I_ERR_MEM)
		write_error("Failed to allocate memory.");
	else if (errcode == I_ERR_MUTEX)
		write_error("Failed to init mutex.");
}
