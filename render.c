#include "fdf.h"



void	normalization(t_var *var)
{
	int map_x;
	int map_y;

	if (var->cols > var->rows)
		var->scale = WIDTH / 2 / var->cols;
	else
		var->scale = HEIGHT / 2 / var->cols;
	map_x = (var->scale * (var->cols - 1));
	var->n_x = (1920 - map_x)/2;
	map_y = (var->scale * (var->rows - 1));
	var->n_y = (1080 - map_y)/2;

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
		img_put_pixel(var, var->x, var->y);
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
		var->z0 = var->map[y][x]->s_z + var->scale + var->alt;
		var->z1 = var->map[y][x + 1]->s_z +var->scale + var->alt;
		set_coords(fdf, k, n);
		set_coords(fdf, k, n + 1);
		fdf->x_curr = fdf->x0;
		fdf->y_curr = fdf->y0;
		fdf->color_curr = fdf->color0;
		draw_line(fdf);
	}
	if (x + 1 < fdf->rows)
	{
		var->z0 = var->map[y][x]->s_z + var->scale + var->alt;
		var->z1 = var->map[y + 1][x]->s_z +var->scale + var->alt;
		set_coords(fdf, k, n);
		set_coords(fdf, k + 1, n);
		fdf->x_curr = fdf->x0;
		fdf->y_curr = fdf->y0;
		fdf->color_curr = fdf->color0;
		draw_line(fdf);
	}
}

void	rot(t_var *var, int y, int x, int yy)
{
	int xx;
	int zz;

	while (++y < var->rows)
	{
		while (++x < var->cols)
		{
			var->map[y][x]->x = (var->rows - 1) * var->scale / 2 - ((var->cols - 1)
					* var->scale - x * var->scale);
			var->map[y][x]->y = (var->rows - 1) * var->scale / 2 - y * var->scale;
			var->map[y][x]->z = var->map[y][x]->s_z * 5;
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
	}
}

void	render(t_var *var)
{
	int x;
	int y;

	ft_bzero(var->img_addr, WIDTH * HEIGHT * var->bpp / 8);
	normalization(var);
	rot(var, -1, -1, 0);
	y = -1;
	while (++y < var->rows)
	{
		x = -1;
		while (++x < var->cols)
		{
		render_core(var, y, x);
		}
	}

}


