#include "fdf.h"

void	help_menu(t_var *var)
{
	if (var->help_button == 0)
	{
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 5, 0xFFFFFF, "Press H to help");
	}
	else
	{
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 5, 0xFFFFFF,
					   "Press Z or X to change color");
		mlx_string_put(var->mlx_ptr, var->win_ptr, 5, 25, 0xFFFFFF,
					   "Press 1, 2, 3, 4 or 5 to choose different types of projection");
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


