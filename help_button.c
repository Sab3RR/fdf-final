/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:42:29 by vsusol            #+#    #+#             */
/*   Updated: 2019/03/07 17:42:31 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	help_menu(t_var *var)
{
	if (var->help_button == 0)
	{
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 5,
				0xFFFFFF, "Press H to help");
	}
	else
	{
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 5, 0xFFFFFF,
				"Press Z or X to change color");
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 25, 0xFFFFFF,
				"Press 1, 2, 3, 4 or 5 to choose "
	"different types of projection");
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 45, 0xFFFFFF,
				"Press Q, W, E, A, S, D (or use mouse buttons) to rotate");
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 65, 0xFFFFFF,
				"Use arrows to move along X or Y axis");
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 85, 0xFFFFFF,
				"Scroll up/down to change a scale");
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 105, 0xFFFFFF,
				"Scroll left/right to change an altitude");
	}
}

void	rotation(t_var *var, int y, int x, int xx)
{
	int yy;
	int zz;

	var->map[y][x]->x = (var->cols - 1) * var->scale / 2 - ((var->cols - 1)
			* var->scale - x * var->scale);
	var->map[y][x]->y = (var->rows - 1) * var->scale / 2 - y * var->scale;
	var->map[y][x]->z = (int)(var->map[y][x]->s_z * var->scale * var->alt);
	xx = var->map[y][x]->x;
	yy = var->map[y][x]->y;
	zz = var->map[y][x]->z;
	var->map[y][x]->y = (int)(yy * cos(var->rad_y) + zz * sin(var->rad_y));
	var->map[y][x]->z = (int)(-(yy) * sin(var->rad_y) + zz * cos(var->rad_y));
	yy = var->map[y][x]->y;
	zz = var->map[y][x]->z;
	var->map[y][x]->x = (int)(xx * cos(var->rad_x) + zz * sin(var->rad_x));
	var->map[y][x]->z = (int)(-(xx) * sin(var->rad_x) + zz * cos(var->rad_x));
	xx = var->map[y][x]->x;
	var->map[y][x]->x = (int)(xx * cos(var->rad_z) + yy * sin(var->rad_z));
	var->map[y][x]->y = (int)(-(xx) * sin(var->rad_z) + yy * cos(var->rad_z));
}
