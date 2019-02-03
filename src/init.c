
#include "fractol.h"

void	ft_init_image(t_f *lst)
{
	int sizex;
	int sizey;
	int	bpp;
	int endian;

	sizex = WIN_SIZEX;
	sizey = WIN_SIZEY;
	bpp = 4;
	endian = 0;
	lst->img = mlx_new_image(lst->mlx_ptr, sizex, sizey);
	lst->s_img = (unsigned char*)(mlx_get_data_addr(lst->img, &(bpp)
	, &(sizex), &(endian)));
}

void	ft_init_list(t_f *lst)
{
	if (lst->mode == 1)
	{
		lst->x1 = -2.1;
		lst->x2 = 0.6;
		lst->y1 = -1.2;
		lst->y2 = 1.2;
		lst->z_i = 0;
		lst->z_r = 0;
	}
	if (lst->mode == 2)
	{
		lst->x1 = -1.7;
		lst->x2 = 1.7;
		lst->y1 = -1.2;
		lst->y2 = 1.2;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
	}
	if (lst->mode == 3)
	{
		lst->x1 = -2;
		lst->x2 = 2;
		lst->y1 = -2;
		lst->y2 = 2;
		lst->z_i = 0;
		lst->z_r = 0;
	}
	lst->moove = 0;
	lst->iteration = 100;
	lst->x = 0;
	lst->y = 0;
	lst->zoom_x = WIN_SIZEX / (lst->x2 - lst->x1);
	lst->zoom_y = WIN_SIZEY / (lst->y2 - lst->y1);
	lst->mlx_ptr = mlx_init();
	lst->win_ptr = mlx_new_window(lst->mlx_ptr, WIN_SIZEX, WIN_SIZEY,
	"Fractol");
	ft_init_image(lst);
}

void	ft_re_init_list(t_f *lst)
{
	if (lst->mode == 1)
	{
		lst->x1 = -2.1;
		lst->x2 = 0.6;
		lst->y1 = -1.2;
		lst->y2 = 1.2;
		lst->z_i = 0;
		lst->z_r = 0;
	}
	if (lst->mode == 2)
	{
		lst->x1 = -1.5;
		lst->x2 = 1.5;
		lst->y1 = -1.2;
		lst->y2 = 1.2;
		lst->z_i = -0.69;
		lst->z_r = -0.69;
	}
	lst->moove = 0;
	lst->iteration = 100;
	lst->x = 0;
	lst->y = 0;
	lst->zoom_x = WIN_SIZEX / (lst->x2 - lst->x1);
	lst->zoom_y = WIN_SIZEY / (lst->y2 - lst->y1);
}

void	ft_mode(t_f *lst, char **av)
{
	if (av[1][0] == '1')
		lst->mode = 1;
	if (av[1][0] == '2')
		lst->mode = 2;
	if (av[1][0] == '3')
		lst->mode = 3;
	ft_init_list(lst);
}
