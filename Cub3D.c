/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/22 10:58:44 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static image_t	*init_images(mlx_t *mlx, char *path)
{
	image_t			*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error_hanlder(YLW "<mlx>" RST " Failed");
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		error_hanlder(YLW "<mlx>" RST " Failed");
	return (image);
}

int	main(int ac, char **av)
{
	t_cub3d		data;

	ft_bzero(&data, sizeof(t_cub3d));
	data.map.file = ac;
	data.map.load = av[1];
	parser(&data);
	printf("[ %d ]\n", data.colors.floor);
	data.mlx = mlx_init(1080, 720, "Cub3D", false);
	data.images.east = init_images(data.mlx, data.textures.east);
	data.images.west = init_images(data.mlx, data.textures.west);
	data.images.south = init_images(data.mlx, data.textures.south);
	data.images.north = init_images(data.mlx, data.textures.north);
	for (unsigned int i =0; i < data.images.east->height; i++)
	{
		for(unsigned int j = 0; j < data.images.east->width; j++)
			mlx_put_pixel(data.images.east, j, i, data.colors.floor);
	}
	mlx_image_to_window(data.mlx, data.images.east, 100, 100);
	mlx_put_string(data.mlx, "1337", 10, 10);
	mlx_loop(data.mlx);
	return (cleanup(), EXIT_SUCCESS);
}
