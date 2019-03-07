/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:42:55 by vsusol            #+#    #+#             */
/*   Updated: 2019/03/07 17:42:57 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		help_button(int key, t_var *var)
{
	if (key == 4)
	{
		if (var->help_button == 0)
			var->help_button = 1;
		else
			var->help_button = 0;
		render(var);
	}
	return (0);
}

int		deal_key3(int key, t_var *var)
{
	if (key == 21)
	{
		var->rad_x = 1.5708;
		var->rad_y = 0;
		var->rad_z = 0;
	}
	if (key == 23)
	{
		var->rad_x = 1.5708;
		var->rad_y = 0;
		var->rad_z = 1.5708;
	}
	if (key == 123)
		var->shift_x -= 5;
	if (key == 124)
		var->shift_x += 5;
	if (key == 123 || key == 124 || key == 23 || key == 21 ||
		key == 18 || key == 19 || key == 20 || key == 125 || key == 126)
		render(var);
	help_button(key, var);
	if (key == 53)
		exit(0);
	return (0);
}

int		deal_key2(int key, t_var *var)
{
	if (key == 18)
	{
		var->rad_x = 0.959931;
		var->rad_y = 0;
		var->rad_z = 0.785398;
	}
	if (key == 19)
	{
		var->rad_x = 0.523599;
		var->rad_y = 0;
		var->rad_z = 0;
	}
	if (key == 20)
	{
		var->rad_x = 0;
		var->rad_y = 0;
		var->rad_z = 0;
	}
	if (key == 126)
		var->shift_y -= 5;
	if (key == 125)
		var->shift_y += 5;
	deal_key3(key, var);
	return (0);
}

int		deal_key(int key, t_var *var)
{
	if (key == 12)
		var->rad_z -= 0.1;
	if (key == 14)
		var->rad_z += 0.1;
	if (key == 13)
		var->rad_x += 0.1;
	if (key == 1)
		var->rad_x -= 0.1;
	if (key == 0)
		var->rad_y -= 0.1;
	if (key == 2)
		var->rad_y += 0.1;
	if (key == 6)
		var->colordx += 25;
	if (key == 7)
		var->colordx -= 25;
	if (key == 12 || key == 14 || key == 13 || key == 6 || key == 7 ||
		key == 0 || key == 1 || key == 2)
		render(var);
	deal_key2(key, var);
	return (0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
