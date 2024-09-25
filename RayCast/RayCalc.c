/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayCalc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:22:30 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/24 22:30:06 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

double	calc_dist(double fx, double fy, double sx, double sy)
{
	return (sqrt((sx - fx) * (sx - fx) + (sy - fy) * (sy - fy)));
}

int	check_ray_dir_down_up(double angle)
{
	if (angle > 0 && angle < M_PI)
			return (1);
	return (0);
}

int	check_ray_dir_righ_left(double angle)
{
	if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)
			return (1);
	return (0);
}

double	ranging_angle(double angle)
{
	double	angle_range;

	angle_range = remainder(angle, (2 * M_PI));
	if (angle_range < 0)
		angle_range += 2 * M_PI;
	return (angle_range);
}
