/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:37:59 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/16 10:38:09 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cub3D.h"

void	parcer(int ac, char **av)
{
	if (ac != 2)
		error_hanlder(1);
	if (!ft_strrchr(av[1], '.') || ft_strcmp(ft_strrchr(av[1], '.'), ".cub"))
		error_hanlder(2);
}
