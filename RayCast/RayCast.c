/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayCast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:15:35 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/24 22:30:03 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	cast_the_ray_horz(t_ray *ray)
{
	double	inter_x;
	double	inter_y;
	double	next_on_wallx;
	double	next_on_wally;
	double	check_next_on_wally;
	double	step_x;
	double	step_y;

	inter_y = TILE * floor(data()->player.pos_y / TILE);
	if (check_ray_dir_down_up(ray->angle))
		inter_y += TILE;
	inter_x = data()->player.pos_x + (inter_y - data()->player.pos_y) / tan(ray->angle);
	step_y = TILE;
	if (!check_ray_dir_down_up(ray->angle))
		step_y *= -1;
	step_x = (TILE * (inter_x - data()->player.pos_x)) / (inter_y - data()->player.pos_y);
	if (check_ray_dir_righ_left(ray->angle) && step_x < 0)
		step_x *= -1;
	if (!check_ray_dir_righ_left(ray->angle) && step_x > 0)
		step_x *= -1;
	next_on_wallx = inter_x;
	next_on_wally = inter_y;
	while (next_on_wallx >= 0 && next_on_wallx < WIN_WIDTH && next_on_wally >= 0 && next_on_wally < WIN_HEIGHT)
	{
		check_next_on_wally = next_on_wally;
		if (!check_ray_dir_down_up(ray->angle))
			check_next_on_wally--;
		if (check_player_in_wall(check_next_on_wally, next_on_wallx))
		{
			ray->wall_horz_x = next_on_wallx;
			ray->wall_horz_y = next_on_wally;
			return (1);
		}
		else
		{
			next_on_wallx += step_x;
			next_on_wally += step_y;
		}
	}
	return (0);
}

int	cast_the_ray_vert(t_ray *ray)
{
	double	inter_x;
	double	inter_y;
	double	next_on_wallx;
	double	check_next_on_wallx;
	double	next_on_wally;
	double	step_x;
	double	step_y;

	inter_x = TILE * floor(data()->player.pos_x / TILE);
	if (check_ray_dir_righ_left(ray->angle))
		inter_x += TILE;
	inter_y = data()->player.pos_y + ((inter_x - data()->player.pos_x) * tan(ray->angle));
	step_x = TILE;
	if (!check_ray_dir_righ_left(ray->angle))
		step_x *= -1;
	step_y = (TILE * (inter_y - data()->player.pos_y)) / (inter_x - data()->player.pos_x);
	if (!check_ray_dir_down_up(ray->angle) && step_y > 0)
		step_y *= -1;
	if (check_ray_dir_down_up(ray->angle) && step_y < 0)
		step_y *= -1;
	next_on_wallx = inter_x;
	next_on_wally = inter_y;
	while (next_on_wallx >= 0 && next_on_wallx <= WIN_WIDTH && next_on_wally >= 0 && next_on_wally <= WIN_HEIGHT)
	{
		check_next_on_wallx = next_on_wallx;
		if (!check_ray_dir_righ_left(ray->angle))
			check_next_on_wallx--;
		if (check_player_in_wall(next_on_wally, check_next_on_wallx))
		{
			ray->wall_vert_x = next_on_wallx;
			ray->wall_vert_y = next_on_wally;
			return (1);
		}
		else
		{
			next_on_wallx += step_x;
			next_on_wally += step_y;
		}
	}
	return (0);
}

void	cast_the_ray(int i)
{
	t_ray	ray;
	double	horz_touch;
	double	vert_touch;

	ray = data()->rays[i];
	horz_touch = 0;
	vert_touch = 0;
	if (cast_the_ray_horz(&ray))
	{
		horz_touch = calc_dist(data()->player.pos_x, data()->player.pos_y, \
		ray.wall_horz_x, ray.wall_horz_y);
	}
	else
		horz_touch = MAXFLOAT;
	if (cast_the_ray_vert(&ray))
	{
		vert_touch = calc_dist(data()->player.pos_x, data()->player.pos_y, \
		ray.wall_vert_x, ray.wall_vert_y);
	}
	else
		vert_touch = MAXFLOAT;
	if (horz_touch > vert_touch)
		ray.distance = vert_touch;
	else
		ray.distance = horz_touch;
	data()->rays[i] = ray;
}

void	raycasting(void)
{
	int		i;
	double	angle;

	i = 0;
	angle = ranging_angle(data()->player.angle - (FOV / 2));
	data()->rays = allocate(WIN_WIDTH, sizeof(t_ray));
	while (i < WIN_WIDTH)
	{
		data()->rays[i].wall_horz_x = 0;
		data()->rays[i].wall_horz_y = 0;
		data()->rays[i].wall_vert_x = 0;
		data()->rays[i].wall_vert_y = 0;
		data()->rays[i].distance = 0;
		data()->rays[i].col_i = i;
		data()->rays[i].angle = ranging_angle(angle);
		cast_the_ray(i);
		angle +=(FOV / (WIN_WIDTH));
		i++;
	}
}
