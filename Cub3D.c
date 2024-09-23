/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/23 11:47:19 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_cub3d	*data(void)
{
	static short		set;
	static t_cub3d		data;

	if (set == 0)
	{
		ft_bzero(&data, sizeof(t_cub3d));
		set = 1;
	}
	return (&data);
}

static mlx_image_t	*init_image(char *path)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error_hanlder(YELLOW "<mlx>" RESET " Failed");
	image = mlx_texture_to_image(data()->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		error_hanlder(YELLOW "<mlx>" RESET " Failed");
	return (image);
}

int	main(int ac, char **av)
{
	data()->map.file = ac;
	data()->map.load = av[1];
	parser();
	data()->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", false);
	if (!data()->mlx)
		error_hanlder(YELLOW "<mlx>" RESET " Failed");
	data()->images.east = init_image(data()->textures.east);
	data()->images.west = init_image(data()->textures.west);
	data()->images.south = init_image(data()->textures.south);
	data()->images.north = init_image(data()->textures.north);
	mlx_image_to_window(data()->mlx, data()->images.east, 100, 100);
	mlx_put_string(data()->mlx, "1337", 10, 10);
	mlx_loop(data()->mlx);
	return (cleanup(), EXIT_SUCCESS);
}
