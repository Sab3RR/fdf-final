/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:44:04 by vsusol            #+#    #+#             */
/*   Updated: 2019/03/07 17:44:05 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int curr)
{
	double place;
	double dist;

	place = curr - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int		get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

void	get_color(t_var *var)
{
	int		red;
	int		green;
	int		blue;
	double	perc;

	if (var->color0 == var->color1)
		return ;
	if (var->dx > var->dy)
		perc = percent(var->x0, var->x1, var->x);
	else
		perc = percent(var->y0, var->y1, var->y);
	red = get_light((var->color0 >> 16) & 0xFF,
			(var->color1 >> 16) & 0xFF, perc);
	green = get_light((var->color0 >> 8) & 0xFF,
			(var->color1 >> 8) & 0xFF, perc);
	blue = get_light(var->color0 & 0xFF, var->color1 & 0xFF, perc);
	var->color = (red << 16) | (green << 8) | blue;
}

void	set_coords(t_var *var, int y, int x)
{
	var->x0 = var->x1;
	var->y0 = var->y1;
	var->z0 = var->z1;
	var->color0 = var->color1;
	var->x1 = var->n_x + (var->cols - 1) * var->scale / 2 + var->map[y][x]->x;
	var->y1 = var->n_y + (var->rows - 1) * var->scale / 2 - var->map[y][x]->y;
	var->z1 = (int)(var->map[y][x]->s_z * var->alt);
	if (var->z1 > (var->alt * var->max_z * 0.8))
		var->color1 = 0xFFFFFF;
	else if (var->z1 > (var->alt * var->max_z / 3))
		var->color1 = 0x35CCF5;
	else if (var->z1 > 0)
		var->color1 = 0x036836;
	else if (var->z1 < (-var->alt * var->max_z))
		var->color1 = 0xE13213;
	else if (var->z1 < (-var->alt * var->max_z / 5))
		var->color1 = 0x2A078D;
	else
		var->color1 = 0x04A92E;
}

void	put_pixel(t_var *var, int y, int x)
{
	int	color;

	get_color(var);
	color = var->color + var->colordx;
	x = x + var->shift_x;
	y = y + var->shift_y;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int*)(var->img_addr + ((x + y * WIDTH) * var->bpp / 8)) = color;
}
