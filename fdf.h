/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:36:13 by vsusol            #+#    #+#             */
/*   Updated: 2019/03/07 17:38:49 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_map
{
	int			x;
	int			y;
	int			z;
	int			s_z;
}				t_map;

typedef struct	s_var
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_addr;
	int			fd;
	int			bpp;
	int			size_line;
	int			endian;
	t_map		***map;
	int			cols;
	int			rows;
	char		*name;
	double		rad_x;
	double		rad_y;
	double		rad_z;
	int			x;
	int			y;
	int			scale;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			n_x;
	int			n_y;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			z0;
	int			z1;
	double		alt;
	int			color;
	int			color0;
	int			color1;
	int			shift_x;
	int			shift_y;
	int			max_z;
	int			min_z;
	int			colordx;
	int			last_x;
	int			last_y;
	int			button;
	int			help_button;
}				t_var;

void			render(t_var *var);
void			set_coords(t_var *var, int y, int x);
void			put_pixel(t_var *var, int y, int x);
void			normalization(t_var *var);
int				move_mouse(int x, int y, t_var *var);
int				mouse_key(int button, int x, int y, t_var *var);
int				key_realise(int button, int x, int y, t_var *var);
int				deal_key(int key, t_var *var);
int				ft_close(void *param);
void			help_menu(t_var *var);
void			rotation(t_var *var, int y, int x, int xx);

#endif
