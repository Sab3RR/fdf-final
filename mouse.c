/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:43:49 by vsusol            #+#    #+#             */
/*   Updated: 2019/03/07 17:43:52 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_y(t_var *var, int y)
{
	if (var->last_y != -1)
	{
		if (var->rad_y > 6.28319)
			var->rad_y = var->rad_y - 6.28319;
		if (var->rad_y < -6.28319)
			var->rad_y = var->rad_y + 6.28319;
		var->rad_y -= (y - var->last_y) * 0.0014544 * 4;
		var->last_y = y;
	}
	else
	{
		var->last_y = y;
	}
}

void	rot_x(t_var *var, int x)
{
	if (var->last_x != -1)
	{
		if (var->rad_x > 6.28319)
			var->rad_x = var->rad_x - 6.28319;
		if (var->rad_x < 0)
			var->rad_x = var->rad_x + 6.28319;
		var->rad_x += (x - var->last_x) * 0.0014544 * 4;
		var->last_x = x;
	}
	else
	{
		var->last_x = x;
	}
}

int		move_mouse(int x, int y, t_var *var)
{
	int button;

	button = var->button;
	if (button == 1)
	{
		rot_y(var, y);
		rot_x(var, x);
	}
	else
	{
		var->last_y = -1;
		var->last_x = -1;
	}
	render(var);
	return (0);
}

int		mouse_key(int button, int x, int y, t_var *var)
{
	(void)x;
	(void)y;
	if (button == 1)
		var->button = 1;
	else if (button == 2)
		var->button = 2;
	else if (button == 4)
		var->scale += 1;
	else if (button == 5)
	{
		if (var->scale > 1)
			var->scale -= 1;
	}
	else if (button == 6)
		var->alt -= 0.1;
	else if (button == 7)
		var->alt += 0.1;
	render(var);
	return (0);
}

int		key_realise(int button, int x, int y, t_var *var)
{
	(void)x;
	(void)y;
	(void)button;
	var->button = 0;
	return (0);
}
