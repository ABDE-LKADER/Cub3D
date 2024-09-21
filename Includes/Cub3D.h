/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:41 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/21 14:24:34 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "CLib.h"
# include "Types_Cub3D.h"

# define error -1

# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define RED "\033[1;31m"
# define RST "\033[0m"

# define USAGE_ERROR YLW"Usage: "RST"./Cub3d <filename.ber>"
# define EXTANSION_ERROR "Input must have "YLW"\".cub\""RST" extension."
# define INVALID_MAP_ERROR "Invalid "YLW"<Map>"

void	error_hanlder(char *message);
void	parser(t_cub3d *data);
void	parse_map(t_cub3d *data);
color_t	parse_color(char *object);
bool	valid_player_symbols(char symbol);
bool	map_invalid_symbols(char *line);
char	*parse_texture(char *object);

#endif
