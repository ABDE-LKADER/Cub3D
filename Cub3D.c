/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/22 16:55:22 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_cub3d	*data(void)
{
	static t_cub3d		data;

	return (&data);
}

static image_t	*init_images(char *path)
{
	image_t			*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error_hanlder(YLW "<mlx>" RST " Failed");
	image = mlx_texture_to_image(data()->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		error_hanlder(YLW "<mlx>" RST " Failed");
	return (image);
}

int	main(int ac, char **av)
{
	ft_bzero(data(), sizeof(t_cub3d));
	data()->map.file = ac;
	data()->map.load = av[1];
	parser();
	data()->mlx = mlx_init(1080, 720, "Cub3D", false);
	data()->images.east = init_images(data()->textures.east);
	data()->images.west = init_images(data()->textures.west);
	data()->images.south = init_images(data()->textures.south);
	data()->images.north = init_images(data()->textures.north);
	mlx_image_to_window(data()->mlx, data()->images.east, 100, 100);
	mlx_put_string(data()->mlx, "1337", 10, 10);
	mlx_loop(data()->mlx);
	return (cleanup(), EXIT_SUCCESS);
}
