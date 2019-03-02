#include "fdf.h"




void	create_map(t_var *var)
{
	int 	x;
	int		y;
	char 	*line;
	char 	**numer;

	var->map = (t_map***)ft_memalloc(sizeof(t_map**) * var->rows);
	y = 0;
	while (get_next_line(var->fd, &line) > 0)
	{
		var->map[y] = (t_map**)ft_memalloc(sizeof(t_map*) * var->cols);
		numer = ft_strsplit(line, ' ');
		x = 0;
		while (x < var->cols)
		{
			var->map[y][x] = (t_map*)ft_memalloc(sizeof(t_map));
			var->map[y][x]->s_z = ft_atoi(numer[x]);
			x++;
		}
		free(line);
		ft_memdel_arr((void***)&numer);
		y++;
	}
	free(line);
}

void	count_map(t_var *var)
{
	int 	n;
	char 	*line;
	char 	**numer;

	var->rows = 0;
	var->cols = -1;
	while (get_next_line(var->fd, &line) > 0)
	{
		numer = ft_strsplit(line, ' ');
		n = 0;
		while (numer[n])
			n++;
		if (var->cols == -1)
			var->cols = n;
		else if (var->cols != n)
		{
			ft_putstr("Invalid File\n");
			exit(0);
		}
		free(line);
		ft_memdel_arr((void***)&numer);
		var->rows++;
	}
	free(line);
}
void	start(t_var *var)
{
	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, WIDTH, HEIGHT, "fdf 42");
	var->img_ptr = mlx_new_image(var->mlx_ptr, WIDTH, HEIGHT);
	var->bpp = 32;
	var->img_addr = mlx_get_data_addr(var->img_ptr, &var->bpp, &var->size_line, &var->endian);
	count_map(var);
	close(var->fd);
	var->fd = open(var->name, O_RDONLY);
	create_map(var);
	render(var);
}

int 	main(int ac, char **av)
{
	t_var *var;
//	if (ac != 2) {
//		ft_putstr("Invalid Argument\n");
//		return (0);
//	}
	if (!(var = (t_var *) ft_memalloc(sizeof(t_var))))
		return (0);
//	var->name = av[1];
	var->name = "42.fdf";
	if ((var->fd = open(var->name, O_RDONLY)) == -1)
	{
		ft_putstr("Invalid Filename\n");
		free(var);
		return (0);
	}
	start(var);


	return (0);
}
