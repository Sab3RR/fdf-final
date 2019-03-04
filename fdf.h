//
// Created by Vadim SUSOL on 2019-02-28.
//

#ifndef FDF_H
#define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_map
{
	int 		x;
	int 		y;
	int 		z;
	int 		s_z;
}				t_map;

typedef struct	s_var
{
	void		*mlx_ptr;
	void		*win_ptr;
	void 		*img_ptr;
	char		*img_addr;
	int 		fd;
	int 		bpp;
	int			size_line;
	int 		endian;
	t_map		***map;
	int 		cols;
	int 		rows;
	char 		*name;
	double 		rad_x;
	double 		rad_y;
	double 		rad_z;
	int 		x;
	int 		y;
	int 		scale;
	int 		x0;
	int 		x1;
	int 		y0;
	int 		y1;
	int 		n_x;
	int 		n_y;
	int 		dx;
	int 		dy;
	int 		sx;
	int 		sy;
	int			z0;
	int 		z1;
	int 		alt;
	int 		color;
	int 		color0;
	int 		shift_x;
	int 		shift_y;
}				t_var;

void	render(t_var *var);
void	set_coords(t_var *var, int y, int x);
void	put_pixel(t_var *var, int y, int x);
#endif //FDF_FDF_H
