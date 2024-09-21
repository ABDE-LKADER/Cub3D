/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:11:55 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/21 18:23:49 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static void	init_map_loader(t_cub3d *data)
{
	char	*line;
	int		lenline;

	lenline = 0;
	while (true)
	{
		line = get_next_line(data->map.file);
		if (line == NULL)
			break ;
		if (*line == '\n')
			error_hanlder(INVALID_MAP_ERROR);
		lenline = strlen_set(line, '\n');
		if (lenline > data->map.longline)
			data->map.longline = lenline;
		data->map.load = ft_strjoin(data->map.load, line);
	}
}

static void	normalize_map_shape(char **grid, int longline)
{
	int		index;
	int		lenline;
	char	*newline;

	index = 0;
	while (grid[index])
	{
		lenline = ft_strlen(grid[index]);
		if (lenline < longline)
		{
			newline = allocate(longline + 1, sizeof(char));
			ft_strlcpy(newline, grid[index], lenline + 1);
			ft_memset(newline + lenline, ' ', longline);
			newline[longline] = '\0';
			grid[index] = newline;
		}
		index++;
	}
}

static void	is_map_surrounded(t_map *map, int height)
{
	int		width;
	char	**grid;

	width = -1;
	grid = map->grid;
	while (grid[height][++width])
	{
		if (valid_player_symbols(grid[height][width]) == false
			&& grid[height][width] != '0')
			continue ;
		if (!height || !width || !grid[height + 1] || width == map->longline - 1
			|| grid[height + 1][width] == ' ' || grid[height - 1][width] == ' '
			|| grid[height][width + 1] == ' ' || grid[height][width - 1] == ' ')
			error_hanlder(INVALID_MAP_ERROR);
	}
}

void	parse_map(t_cub3d *data)
{
	int		height;

	height = 0;
	while (true)
	{
		data->map.load = get_next_line(data->map.file);
		if (data->map.load && *data->map.load == '\n')
			continue ;
		break ;
	}
	init_map_loader(data);
	if (map_invalid_symbols(data->map.load) == true)
		error_hanlder(INVALID_MAP_ERROR);
	data->map.grid = ft_split(data->map.load, '\n');
	normalize_map_shape(data->map.grid, data->map.longline);
	while (data->map.grid[height])
		is_map_surrounded(&data->map, height++);
}
