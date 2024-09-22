/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:37:59 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/22 10:57:51 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static bool	valid_elements(t_cub3d *data)
{
	if (data->colors.ceiling >= 0 && data->colors.floor >= 0
		&& data->textures.north && data->textures.south
		&& data->textures.west && data->textures.east)
		return (true);
	return (false);
}

bool	duplicated_elements(t_cub3d *data, char set)
{
	if ((set == 'N' && data->textures.north)
		|| (set == 'S' && data->textures.south)
		|| (set == 'W' && data->textures.west)
		|| (set == 'E' && data->textures.east)
		|| (set == 'F' && data->colors.floor >= 0)
		|| (set == 'C' && data->colors.ceiling >= 0))
		error_hanlder(INVALID_MAP_ERROR);
	return (true);
}

static void	parse_elements(t_cub3d *data, char *object)
{
	if (ft_strncmp(object, "EA ", ft_strlen("EA ")) == 0)
		data->textures.east = parse_texture(data, object);
	else if (ft_strncmp(object, "WE ", ft_strlen("WE ")) == 0)
		data->textures.west = parse_texture(data, object);
	else if (ft_strncmp(object, "SO ", ft_strlen("SO ")) == 0)
		data->textures.south = parse_texture(data, object);
	else if (ft_strncmp(object, "NO ", ft_strlen("NO ")) == 0)
		data->textures.north = parse_texture(data, object);
	else if (ft_strncmp(object, "C ", ft_strlen("C ")) == 0)
		data->colors.ceiling = parse_color(data, object);
	else if (ft_strncmp(object, "F ", ft_strlen("F ")) == 0)
		data->colors.floor = parse_color(data, object);
	else if (*object)
		error_hanlder(INVALID_MAP_ERROR);
}

void	parser(t_cub3d *data)
{
	if (data->map.file != 2)
		error_hanlder(USAGE_ERROR);
	if (ft_strrchr(data->map.load, '.') == NULL
		|| ft_strcmp(ft_strrchr(data->map.load, '.'), ".cub"))
		error_hanlder(EXTANSION_ERROR);
	data->colors.floor = -1;
	data->colors.ceiling = -1;
	data->map.file = open(data->map.load, O_RDONLY);
	while (valid_elements(data) == false)
	{
		data->map.load = ft_strtrim(get_next_line(data->map.file), " \n");
		if (data->map.load == NULL)
			break ;
		parse_elements(data, data->map.load);
	}
	if (valid_elements(data) == false)
		error_hanlder(INVALID_MAP_ERROR);
	parse_map(data);
}
