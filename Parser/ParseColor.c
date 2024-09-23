/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseColor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:11:20 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/23 11:46:26 by abadouab         ###   ########.fr       */
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
			error_hanlder("Invalid " YELLOW "<Map>" RESET);
		if (commas > 2)
			error_hanlder("Invalid " YELLOW "<Map>" RESET);
		index++;
	}
}

static short	string_to_byte(char *string)
{
	short	byte;
	short	index;
	char	**color;

	index = 0;
	color = ft_split(string, ' ');
	if (color == NULL || color[0] == NULL || color[1])
		error_hanlder("Invalid " YELLOW "<Map>" RESET);
	while (string[index] && is_whitespace(string[index]))
		index++;
	byte = 0;
	while (string[index] && ft_isdigit(string[index]))
	{
		byte = byte * 10 + string[index] - 48;
		if (byte > 255)
			error_hanlder("Invalid " YELLOW "<Map>" RESET);
		index++;
	}
	return (byte);
}

int	parse_color(char *object)
{
	int		red;
	int		green;
	int		blue;
	char	**colors;

	object++;
	duplicated_elements(*data()->map.load);
	detect_invalid_symbols(object);
	colors = ft_split(object, ',');
	if (colors == NULL || colors[0] == NULL
		|| colors[1] == NULL || colors[2] == NULL)
		error_hanlder("Invalid " YELLOW "<Map>" RESET);
	red = string_to_byte(colors[0]);
	green = string_to_byte(colors[1]);
	blue = string_to_byte(colors[2]);
	return (red << 16 | green << 8 | blue);
}
