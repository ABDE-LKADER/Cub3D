/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:37:59 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/16 10:38:09 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

bool	valid_element(char *object)
{
	if (ft_strncmp(object, "NO", ft_strlen("NO"))
		|| ft_strncmp(object, "SO", ft_strlen("SO"))
		|| ft_strncmp(object, "WE", ft_strlen("WE"))
		|| ft_strncmp(object, "EA", ft_strlen("EA"))
		|| ft_strncmp(object, "F", ft_strlen("F"))
		|| ft_strncmp(object, "C", ft_strlen("C")))
		return (true);
	return (false);
}

static void	parce_textures(t_cub3d *data)
{
	data->map.file = open(data->map.load, O_RDONLY);
	while (true)
	{
		data->map.load = ft_strtrim(get_next_line(data->map.file), " \n");
		ft_printf("[ %s ]\n", data->map.load);
		if (data->map.load == NULL)
			break ;
		if (*data->map.load && valid_element(data->map.load) == false)
			break ;
	}
	data->map.grid = ft_split(data->map.load, '\n');
}

void	parcer(t_cub3d *data)
{
	if (data->map.file != 2)
		error_hanlder(1);
	if (ft_strrchr(data->map.load, '.') == NULL
		|| ft_strcmp(ft_strrchr(data->map.load, '.'), ".cub"))
		error_hanlder(2);
	parce_textures(data);
	// parce_colors(data);
	// parce_map(data);
}
