/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types_Cub3D.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:33:41 by abadouab          #+#    #+#             */
/*   Updated: 2024/09/21 14:58:08 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_CUB3D_H
# define TYPES_CUB3D_H

# include "MLX42.h"

# define color_t unsigned int
# define image_t mlx_image_t

// Struct for player information
typedef struct s_player
{
	float			x;			// Player's x-coordinate
	float			y;			// Player's y-coordinate
	float			direction;	// Player's direction (angle)
	float			speed;		// Player's movement speed
}					t_player;

// Struct for map data
typedef struct s_map
{
	char			*load;		// loading map file data
	char			**grid;		// 2D array for map grid
	short			file;		// File Descriptor Map
	int				longline;	// The Longest Map Line
}					t_map;

// Struct for textures
typedef struct s_textures
{
	void		*north;		// Texture for north wall
	void		*south;		// Texture for south wall
	void		*east;		// Texture for east wall
	void		*west;		// Texture for west wall
}				t_textures;

// Struct for Images
typedef struct s_image
{
	image_t		*north;		// Images for north wall
	image_t		*south;		// Images for south wall
	image_t		*east;		// Images for east wall
	image_t		*west;		// Images for west wall
}				t_image;

// Struct for floor and ceiling colors
typedef struct s_colors
{
	color_t			floor;		// Floor color (in RGB format)
	color_t			ceiling;	// Ceiling color (in RGB format)
}					t_colors;

// Main Cub3D struct integrating all components
typedef struct s_cub3d
{
	mlx_t			*mlx;		// Pointer to Main MLX
	t_map			map;		// Map data
	t_textures		texture;	// Texture images
	t_image			images;		// Wall images
	t_colors		colors;		// Floor and ceiling colors
	t_player		player;		// Player information
}					t_cub3d;

#endif
