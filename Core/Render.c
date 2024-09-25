/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:02:18 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/25 14:05:15 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void ft_put_pixel(char color, int x, int y)
{
	int i;
	int j;

	i = y * TILE;
	while (i < y * TILE + TILE)
	{
		j = x * TILE;
		while ( j < x * TILE + TILE)
		{
			if (color == 'r')
				mlx_put_pixel(data()->images.screen, i, j, ft_pixel(255, 0, 0, 255));
			else if (color == 'b')
				mlx_put_pixel(data()->images.screen, i, j, ft_pixel(0, 0, 0, 255));
			else if (color == 'y')
				mlx_put_pixel(data()->images.screen, i, j, ft_pixel(255, 255, 0, 255));
			j++;
		}
		i++;
	}
}

void draw_rect(double x, double y, double height)
{
	int	j;
	double	alpha;
	
	alpha = (200 / data()->rays[(int)x].distance) * 15;
	if (alpha > 255)
		alpha = 255;
	j = 0;
	while (j < height)
	{
		mlx_put_pixel(data()->images.screen, x, y + j, ft_pixel(255, 255, 255, alpha));
		j++;
	}
}

void	render_map(void)
{
	int x = 0;
	
	while (data()->map.grid[x])
	{
		int y = 0;
		while (data()->map.grid[x][y])
		{
			if (data()->map.grid[x][y] == '1')
				ft_put_pixel('y', x, y);
			else if (data()->map.grid[x][y] == '0' || data()->map.grid[x][y] == 'N')
				ft_put_pixel('b', x, y);
			y++;			
		}
		x++;
	}
}

void	render_walls(void)
{
	int		i;
	double	ray_distance;
	double	distance_proj_plane;
	double	wall_strip_height;

	i = 0;
	while (i < WIN_WIDTH)
	{
		ray_distance = data()->rays[i].distance * cos(data()->rays[i].angle - data()->player.angle);
		distance_proj_plane = (WIN_WIDTH / 2) / tan(FOV / 2);
		wall_strip_height = (TILE / ray_distance) * distance_proj_plane;
		if (wall_strip_height > WIN_HEIGHT)
			wall_strip_height = WIN_HEIGHT;
		if (distance_proj_plane > WIN_WIDTH)
			distance_proj_plane = WIN_WIDTH;
		draw_rect(i, (WIN_HEIGHT / 2) - (wall_strip_height / 2), wall_strip_height);
		i++;
	}
}

void	render(void)
{
	render_walls();
	render_map();
	ft_print_player(data()->player.pos_x - 5, data()->player.pos_y - 5, 11);
}

void ft_hook(void *param)
{
	(void) param;
	if (mlx_is_key_down(data()->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data()->mlx);
	if (mlx_is_key_down(data()->mlx, MLX_KEY_UP))
		data()->player.walk.direction = 1;
	if (mlx_is_key_down(data()->mlx, MLX_KEY_DOWN))
		data()->player.walk.direction = -1;
	if (mlx_is_key_down(data()->mlx, MLX_KEY_LEFT))
		data()->player.rot.direction = -1;
	if (mlx_is_key_down(data()->mlx, MLX_KEY_RIGHT))
		data()->player.rot.direction = 1;
	move_player();
	mlx_delete_image(data()->mlx, data()->images.screen);
	data()->images.screen = mlx_new_image(data()->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(data()->mlx, data()->images.screen, 0, 0);
	raycasting();
	render();
	//printf("cos is %f and sin is %f\n", cos(data()->player->angle), sin(data()->player->angle));
	data()->player.rot.direction = 0;
	data()->player.walk.direction = 0;
	//printf("Angle :%f\n", data()->player->angle * 180 / M_PI);
}
