/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:21:42 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/25 13:27:06 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	error_hanlder(char *message)
{
	if (message)
	{
		ft_putstr_fd(RED"Error:\n"RESET, STDERR_FILENO);
		ft_putstr_fd("Cub3D: ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd(RESET"\n", STDERR_FILENO);
	}
	cleanup();
	if (data()->map.file != ERROR)
		exit(data()->map.file);
	mlx_close_window(data()->mlx);
	exit(EXIT_FAILURE);
}
