/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:41 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/23 11:47:09 by abadouab         ###   ########.fr       */
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

# define ERROR -1

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

t_cub3d	*data(void);
void	error_hanlder(char *message);
void	parser(void);
void	parse_map(void);
int		parse_color(char *object);
bool	valid_player_symbols(char symbol);
bool	map_invalid_symbols(char *line);
char	*parse_texture(char *object);
bool	duplicated_elements(char set);

#endif
