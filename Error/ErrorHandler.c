/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:21:42 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/22 09:04:36 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	error_hanlder(char *message)
{
	if (message)
	{
		ft_putstr_fd(RED"Error:\n"RST, STDERR_FILENO);
		ft_putstr_fd("Cub3D: ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd(RST"\n", STDERR_FILENO);
	}
	cleanup();
	exit(EXIT_FAILURE);
}
