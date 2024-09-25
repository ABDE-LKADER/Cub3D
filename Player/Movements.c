/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:57:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/25 14:39:10 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	ft_print_player(int x, int y, int size)
{
	int i;
	int j;

	i = y;
	while (i < y + size)
	{
		j = x;
		while (j < x + size)
		{
			mlx_put_pixel(data()->images.screen, j, i, ft_pixel(255, 255, 0, 255));
			j++;
		}
		i++;
	}
}

int	check_player_in_wall(double y, double x)
{
	int	index_x;
	int	index_y;
	int	len_x;
	int	len_y;

	index_y = floor(y / TILE);
	index_x = floor(x / TILE);
	len_y = 0;
	while (data()->map.grid[len_y])
		len_y++;
	len_x = ft_strlen(data()->map.grid[0]);
	if (len_y > index_y && len_x > index_x
		&& data()->map.grid[index_y][index_x] == '1')
		return (1);
	return (0);
}

void	move_player(void)
{
	double	x;
	double	y;
	double	step;

	step = 0;
	data()->player.angle += data()->player.rot.direction * data()->player.rot.speed;
	step = data()->player.walk.direction * data()->player.walk.speed;
	x = data()->player.pos_x + cos(data()->player.angle) * step;
	y = data()->player.pos_y + sin(data()->player.angle) * step;
	if (!check_player_in_wall(y + 10, x + 10))
	{
		if (!check_player_in_wall(data()->player.pos_y, x)
			&& !check_player_in_wall(y, data()->player.pos_x))
		{	
			data()->player.pos_x = x;
			data()->player.pos_y = y;
		}
	}
}
	