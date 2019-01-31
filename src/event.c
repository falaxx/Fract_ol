
#include "fractol.h"

int		key_hook(int key, void *param)
{
	t_f *lst;

	lst = (t_f *)param;
	if (key == 53)
		exit(0);
	if (key == 78)
	{
		if (lst->iteration >= 10)
			lst->iteration += 10;
		else if(lst->iteration < 10)
			lst->iteration++;
	}
	if (key == 69)
	{
		if (lst->iteration > 10)
			lst->iteration -= 10;
		else if(lst->iteration > 1)
			lst->iteration--;
	}
	if (key == 124)
		lst->z_i -= 0.01;
	if (key == 123)
		lst->z_i += 0.01;
	if (key == 126)
		lst->z_r -= 0.01;
	if (key == 125)
		lst->z_r += 0.01;

	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst);
	ft_trace(lst);
	return (0);
}

int		mouse_hook(int key, int i, int j, void *param)
{
	t_f *lst;

	lst = (t_f *)param;
	i = j;
	if (key == 5)
	{
		lst->zoom_x+= 10;
		lst->zoom_y+= 10;
	}
	if (key == 4 )
	{
		lst->zoom_x-= 10;
		lst->zoom_y-= 10;
	}
	// ft_putnbr(lst->zoom_x);
	// ft_putchar('\n');
	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst);
	ft_trace(lst);
	return (0);
}

int mouse_move (int i, int j, void *param)
{
	t_f *lst;

	lst = (t_f *)param;
if (i < lst->savei)
	lst->z_i -= 0.01;
if (j < lst->savej)
	lst->z_r -= 0.01;
if (i > lst->savei)
	lst->z_i += 0.01;
if (j > lst->savej)
	lst->z_r += 0.01;
//
//
mlx_destroy_image(lst->mlx_ptr, lst->img);
ft_init_image(lst);
ft_trace(lst);
lst->savei = i;
lst->savej = j;
//
return(0);
}
int		ft_expose(void *param)
{
	t_f *lst;

	lst = (t_f *)param;
	exit(0);
}
