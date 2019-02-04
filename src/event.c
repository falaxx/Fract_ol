
#include "fractol.h"

int		key_hook(int key, void *param)
{
	t_f *lst;

	lst = (t_f *)param;
	if (key == 53)
		exit(0);
	if (key == 18)
		lst->colormode = 1;
	if (key == 19)
		lst->colormode = 2;
	if (key == 20)
		lst->colormode = 3;
	if (key == 21)
		lst->colormode = 4;
	if (key == 22)
		lst->colormode = 5;
	if (key == 23)
		lst->colormode = 6;
	if (key == 26)
		lst->colormode = 7;	
	if (key == 67)
	{
		if (lst->moove == 1)
			lst->moove = 0;
		else
			lst->moove = 1;
	}
	if (key == 69)
	{
		if (lst->iteration >= 10)
			lst->iteration += 10;
		else if (lst->iteration < 10)
			lst->iteration++;
	}
	if (key == 78)
	{
		if (lst->iteration > 10)
			lst->iteration -= 10;
		else if (lst->iteration > 1)
			lst->iteration--;
	}
	if (key == 123)
	{
		lst->x1 -= 30 / lst->zoom_x;
		lst->x2 -= 30 / lst->zoom_x;
	}
	if (key == 124)
	{
		lst->x1 += 30 / lst->zoom_x;
		lst->x2 += 30 / lst->zoom_x;
	}
	if (key == 125)
	{
		lst->y1 += 30 / lst->zoom_y;
		lst->y2 += 30 / lst->zoom_y;
	}
	if (key == 126)
	{
		lst->y1 -= 30 / lst->zoom_y;
		lst->y2 -= 30 / lst->zoom_y;
	}
	if (key == 51)
		ft_init_list(lst);
	if (key == 47)
	{
		lst->mode++;
		if (lst->mode == 9)
			lst->mode = 1;
		ft_init_list(lst);
	}
	if (key == 43)
	{
		lst->mode--;
		if (lst->mode == 0)
			lst->mode = 8;
		ft_init_list(lst);
	}


	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst);
	ft_trace(lst);
	return (0);
}

int		mouse_hook(int key, int x, int y, void *param)
{
	t_f *lst;
	int z;

	lst = (t_f *)param;
	z = 1;
	if (key == 4)
		ft_zoom(x, y, lst, z);
	if (key == 5)
	{
		z = 0;
		ft_zoom(x, y, lst, z);
	}
	// ft_putnbr(lst->zoom_x);
	// ft_putchar('\n');
	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst);
	lst->dejavu = 1;
	ft_trace(lst);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_f *lst;

	lst = (t_f *)param;
	if (lst->moove == 1)
	{
		if (x < lst->savei)
			lst->z_i -= 0.02;
		if (y < lst->savej)
			lst->z_r += 0.02;
		if (x > lst->savei)
			lst->z_i += 0.02;
		if (y > lst->savej)
			lst->z_r -= 0.02;
		ft_putstr("zi");
		ft_putnbr(lst->z_i * 100);
		ft_putstr("zr");
		ft_putnbr(lst->z_i * 100);
		mlx_destroy_image(lst->mlx_ptr, lst->img);
		ft_init_image(lst);
		ft_trace(lst);
		lst->savei = x;
		lst->savej = y;
	}

		ft_putstr("lst->x1 ");
		ft_putnbr(lst->x1*100);

		ft_putchar('\n');
			ft_putstr("lst->x2 ");
		ft_putnbr(lst->x2*100);
		ft_putchar('\n');ft_putstr("lst->y1 ");
		ft_putnbr(lst->y1*100);
		ft_putchar('\n');
		ft_putstr("lst->y2 ");
		ft_putnbr(lst->y2*100);

		ft_putchar('\n');
		ft_putstr("lst->zi ");
		ft_putnbr(lst->z_i*100);
		ft_putchar('\n');
			ft_putstr("lst->zr ");
		ft_putnbr(lst->z_r*100);
		ft_putchar('\n');
	return (0);
}

void	ft_zoom(int x, int y, t_f *lst, int z)
{
	if (z == 1)
	{
		lst->zoom_x *= 1.1;
		lst->zoom_y *= 1.1;
		lst->x1 = (lst->x1 * lst->zoom_x + x - 0.5 * WIN_SIZEX) /
		lst->zoom_x;
		lst->x2 = (lst->x2 * lst->zoom_x + x + 0.5 * WIN_SIZEX) /
		lst->zoom_x;
		lst->y1 = (lst->y1 * lst->zoom_y + y - 0.5 * WIN_SIZEY) /
		lst->zoom_y;
		lst->y2 = (lst->y2 * lst->zoom_y + y + 0.5 * WIN_SIZEY) /
		lst->zoom_y;
	}
	if (z == 0)
	{
		lst->zoom_x *= 0.9;
		lst->zoom_y *= 0.9;
		lst->x1 = (lst->x1 * lst->zoom_x + x - 0.5 * WIN_SIZEX) /
		lst->zoom_x;
		lst->x2 = (lst->x2 * lst->zoom_x + x + 0.5 * WIN_SIZEX) /
		lst->zoom_x;
		lst->y1 = (lst->y1 * lst->zoom_y + y - 0.5 * WIN_SIZEY) /
		lst->zoom_y;
		lst->y2 = (lst->y2 * lst->zoom_y + y + 0.5 * WIN_SIZEY) /
		lst->zoom_y;
	}
}

int		ft_expose(void *param)
{
	t_f *lst;

	lst = (t_f *)param;
	exit(0);
}
