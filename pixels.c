#include "fdf.h"

void	set_coords(t_var *var, int y, int x)
{
	var->x0 = var->x1;
	var->y0 = var->y1;
	var->z0 = var->z1;
//	var->color0 = var->color1;
	var->x1 = var->n_x + (var->cols - 1) * var->scale / 2 + var->map[y][x]->x;
	var->y1 = var->n_y + (var->rows - 1) * var->scale / 2 - var->map[y][x]->y;
	var->z1 = var->map[y][x]->s_z * var->alt;
//	if (fdf->z1 > (fdf->q * fdf->max_z * 0.8))
//		fdf->color1 = 0xFFFFFF;
//	else if (fdf->z1 > (fdf->q * fdf->max_z / 3))
//		fdf->color1 = 0x35CCF5;
//	else if (fdf->z1 > 0)
//		fdf->color1 = 0x036836;
//	else if (fdf->z1 < (-fdf->q * fdf->max_z))
//		fdf->color1 = 0xE13213;
//	else if (fdf->z1 < (-fdf->q * fdf->max_z / 5))
//		fdf->color1 = 0x2A078D;
//	else
//		fdf->color1 = 0x04A92E;
}

void	put_pixel(t_var *var, int y, int x)
{
	int	color;

//	get_color(fdf);
//	color = fdf->color_curr + fdf->color_delta;
	x = x + var->shift_x;
	y = y + var->shift_y;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int*)(var->img_addr + ((x + y * WIDTH) * var->bpp / 8)) = 0x00D800;
}
