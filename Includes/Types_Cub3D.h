/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types_Cub3D.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:41 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/16 10:37:21 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_CUB3D_H
# define TYPES_CUB3D_H

# include "MLX42.h"

// Struct for player information
typedef struct s_player
{
	float		x;			// Player's x-coordinate
	float		y;			// Player's y-coordinate
	float		direction;	// Player's direction (angle)
	float		speed;		// Player's movement speed
}				t_player;

// Struct for map data
typedef struct s_map
{
	char		**grid;		// 2D array for map grid
	int			width;		// Map width
	int			height;		// Map height
}				t_map;

// Struct for textures
typedef struct s_textures
{
	void		*north;		// Texture for north wall
	void		*south;		// Texture for south wall
	void		*east;		// Texture for east wall
	void		*west;		// Texture for west wall
}				t_textures;

// Struct for window and rendering
typedef struct s_window
{
	mlx_t		*mlx;		// Pointer to Main MLX
	int			width;		// Window width
	int			height;		// Window height
}				t_window;

// Struct for floor and ceiling colors
typedef struct s_colors
{
	int			floor;		// Floor color (in RGB format)
	int			ceiling;	// Ceiling color (in RGB format)
}				t_colors;

// Main Cub3D struct integrating all components
typedef struct s_cub3d
{
	t_player	player;		// Player information
	t_map		map;		// Map data
	t_textures	textures;	// Wall textures
	t_window	window;		// Window and rendering data
	t_colors	colors;		// Floor and ceiling colors
}				t_cub3d;

#endif
