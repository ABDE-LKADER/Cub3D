/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/21 16:47:21 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cub3D.h"

// void	lk(void){ system("leaks Cub3D"); }
int	main(int ac, char **av)
{
	t_cub3d		data;

	// atexit(lk);
	ft_bzero(&data, sizeof(t_cub3d));
	data.map.file = ac;
	data.map.load = av[1];
	parser(&data);
	// data.mlx = mlx_init(1080, 720, "Cub3D", false);
	// mlx_put_string(data.mlx, "1337", 10, 10);
	// mlx_loop(data.mlx);
	printf("SUCCESS\n");
	return (cleanup(), EXIT_SUCCESS);
}
