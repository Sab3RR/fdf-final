/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:44:20 by vsusol            #+#    #+#             */
/*   Updated: 2019/03/07 17:44:21 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalization(t_var *var)
{
	int map_x;
	int map_y;

	map_x = (var->scale * (var->cols - 1));
	var->n_x = (1920 - map_x) / 2;
	map_y = (var->scale * (var->rows - 1));
	var->n_y = (1080 - map_y) / 2;
}

void	line(t_var *var)
{
	int error[2];

	var->dx = abs(var->x1 - var->x0);
	var->dy = -abs(var->y1 - var->y0);
	var->sx = var->x0 < var->x1 ? 1 : -1;
	var->sy = var->y0 < var->y1 ? 1 : -1;
	error[0] = var->dx + var->dy;
	while (1)
	{
		put_pixel(var, var->y, var->x);
		if (var->x == var->x1 && var->y == var->y1)
			break ;
		error[1] = 2 * error[0];
		if (error[1] >= var->dy)
		{
			error[0] += var->dy;
			var->x += var->sx;
		}
		if (error[1] <= var->dx)
		{
			error[0] += var->dx;
			var->y += var->sy;
		}
	}
}

void	render_core(t_var *var, int y, int x)
{
	if (x + 1 < var->cols)
	{
		set_coords(var, y, x);
		set_coords(var, y, x + 1);
		var->x = var->x0;
		var->y = var->y0;
		var->color = var->color0;
		line(var);
	}
	if (y + 1 < var->rows)
	{
		set_coords(var, y, x);
		set_coords(var, y + 1, x);
		var->x = var->x0;
		var->y = var->y0;
		var->color = var->color0;
		line(var);
	}
}

void	rot(t_var *var, int y, int x)
{
	while (++y < var->rows)
	{
		x = -1;
		while (++x < var->cols)
		{
			rotation(var, y, x, 0);
		}
	}
}

void	render(t_var *var)
{
	int x;
	int y;

	ft_bzero(var->img_addr, (size_t)(WIDTH * HEIGHT * var->bpp / 8));
	normalization(var);
	rot(var, -1, -1);
	y = -1;
	while (++y < var->rows)
	{
		x = -1;
		while (++x < var->cols)
		{
			render_core(var, y, x);
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr, 0, 0);
	help_menu(var);
	printf("rad_x %f\n",var->rad_x);
	printf("rad_y %f\n", var->rad_y);
	printf("rad_z %f\n", var->rad_z);
}
