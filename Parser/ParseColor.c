/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseColor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:11:20 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/21 14:57:37 by abadouab         ###   ########.fr       */
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
			error_hanlder(INVALID_MAP_ERROR RST " COLOR SYMBOL NOT VALID");
		if (commas > 2)
			error_hanlder(INVALID_MAP_ERROR RST " COLOR FORMAT R,G,B NOT VALID");
		index++;
	}
}

static color_t	string_to_byte(char *str)
{
	short	byte;
	int		index;

	index = 0;
	while (is_whitespace(str[index]))
		index++;
	byte = 0;
	while (str[index] && ft_isdigit(str[index]))
	{
		byte = byte * 10 + str[index] - 48;
		if (byte > 255)
			error_hanlder(INVALID_MAP_ERROR RST " COLOR RANGE NOT VALID");
		index++;
	}
	return (byte);
}

color_t	parse_color(char *object)
{
	color_t	red;
	color_t	green;
	color_t	blue;
	char			**colors;

	detect_invalid_symbols(object);
	colors = ft_split(object, ',');
	if (colors == NULL || colors[0] == NULL
		|| colors[1] == NULL || colors[2] == NULL)
		error_hanlder(INVALID_MAP_ERROR RST " COLOR FORMAT R,G,B NOT VALID");
	red = string_to_byte(colors[0]);
	green = string_to_byte(colors[1]);
	blue = string_to_byte(colors[2]);
	return (red << 16 | green << 8 | blue);
}
