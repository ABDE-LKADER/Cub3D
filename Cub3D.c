/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/16 10:52:19 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cub3D.h"

int	main(int ac, char **av)
{
	t_cub3d		data;

	ft_bzero(&data, sizeof(t_cub3d));
	data.map.file = ac;
	data.map.load = av[1];
	parcer(&data);
	// data.mlx = mlx_init(1080, 720, "Cub3D", false);
	// mlx_put_string(data.mlx, "1337", 10, 10);
	// mlx_loop(data.mlx);
	return (cleanup(), EXIT_SUCCESS);
}
