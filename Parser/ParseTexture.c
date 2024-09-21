/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseTexture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:11:18 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/21 15:09:24 by abadouab         ###   ########.fr       */
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
		error_hanlder(INVALID_MAP_ERROR RST " : Player");
	return (false);
}

char	*parse_texture(char *object)
{
	char			**path;

	path = ft_split(object, ' ');
	if (path == NULL || path[0] == NULL || path[1])
		error_hanlder(INVALID_MAP_ERROR RST " TEXTURE FORMAT NOT VALID");
	return (*path);
}
