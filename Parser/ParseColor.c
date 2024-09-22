/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseColor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:11:20 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/22 10:57:34 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static void	detect_invalid_symbols(char *object)
{
	int	index;
	int	commas;

	index = 0;
	commas = 0;
	while (object[index])
	{
		if (object[index] == ',')
			commas++;
		else if (ft_isdigit(object[index]) == 0 && object[index] != ' ')
			error_hanlder(INVALID_MAP_ERROR);
		if (commas > 2)
			error_hanlder(INVALID_MAP_ERROR);
		index++;
	}
}

static short	string_to_byte(char *str)
{
	short	byte;
	short	index;

	index = 0;
	while (is_whitespace(str[index]))
		index++;
	byte = 0;
	while (str[index] && ft_isdigit(str[index]))
	{
		byte = byte * 10 + str[index] - 48;
		if (byte > 255)
			error_hanlder(INVALID_MAP_ERROR);
		index++;
	}
	return (byte);
}

int	parse_color(t_cub3d *data, char *object)
{
	int		red;
	int		green;
	int		blue;
	char	**colors;

	object++;
	duplicated_elements(data, *data->map.load);
	detect_invalid_symbols(object);
	colors = ft_split(object, ',');
	if (colors == NULL || colors[0] == NULL
		|| colors[1] == NULL || colors[2] == NULL)
		error_hanlder(INVALID_MAP_ERROR);
	red = string_to_byte(colors[0]);
	green = string_to_byte(colors[1]);
	blue = string_to_byte(colors[2]);
	return (red << 16 | green << 8 | blue);
}
