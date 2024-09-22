/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseTexture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:11:18 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/22 16:55:22 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

bool	valid_player_symbols(char symbol)
{
	if (symbol == 'N' || symbol == 'S'
		|| symbol == 'W' || symbol == 'E')
		return (true);
	return (false);
}

bool	map_invalid_symbols(char *line)
{
	int		i;
	int		player;

	i = 0;
	player = 0;
	while (line && line[i])
	{
		if (valid_player_symbols(line[i]) == true)
			player++;
		if (valid_player_symbols(line[i]) == false && line[i] != '1'
			&& line[i] != '0' && line[i] != ' ' && line[i] != '\n')
			return (true);
		i++;
	}
	if (player != 1)
		error_hanlder(INVALID_MAP_ERROR);
	return (false);
}

char	*parse_texture(char *object)
{
	int		file;

	object += 2;
	while (*object == ' ')
		object++;
	duplicated_elements(*data()->map.load);
	file = open(object, O_RDONLY);
	if (file == error)
		error_hanlder(INVALID_MAP_ERROR);
	return (close(file), object);
}
