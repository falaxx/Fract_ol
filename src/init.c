
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

// void	ft_init_image_menu(t_f *lst)
// {
// 	int sizex;
// 	int sizey;
// 	int	bpp;
// 	int endian;
//
// 	sizex = WIN_SIZEX/4;
// 	sizey = WIN_SIZEY/5;
// 	bpp = 4;
// 	endian = 0;
// 	lst->img = mlx_new_image(lst->mlx_ptr, sizex, sizey);
// 	lst->s_img = (unsigned char*)(mlx_get_data_addr(lst->img, &(bpp)
// 	, &(sizex), &(endian)));
// 	ft_lightup_menu(lst);
// }

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
		lst->x1 = -1.5;
		lst->x2 = 1.5;
		lst->y1 = -1.2;
		lst->y2 = 1.2;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
		// lst->z_i = 0.01;
		// lst->z_r = 0.285;
	}
	if (lst->mode == 3)
	{
		lst->x1 = -1.7;
		lst->x2 = 1.7;
		lst->y1 = -1.2;
		lst->y2 = 1.2;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
	}
	if (lst->mode == 4)
	{
		lst->x1 = -1.7;
		lst->x2 = 1.2;
		lst->y1 = -1.4;
		lst->y2 = 0.4;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
	}
	if (lst->mode == 5)
	{
		lst->x1 = -2;
		lst->x2 = -0.2;
		lst->y1 = -0.2;
		lst->y2 = 0.4;
		lst->z_i = -0.33;
		lst->z_r = -1.444;
	}
	if (lst->mode == 6)
	{
		lst->x1 = -2.3;
		lst->x2 = -0.2;
		lst->y1 = -0.55;
		lst->y2 = 0.55;
		lst->z_i = 0.96;
		lst->z_r = -0.35;
	}
	if (lst->mode == 7)
	{
		lst->x1 = -8;
		lst->x2 = 1;
		lst->y1 = -3;
		lst->y2 = 3;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
	}
	if (lst->mode == 8)
	{
		lst->x1 = -1;
		lst->x2 = 1;
		lst->y1 = -1.8;
		lst->y2 = 1.8;
		lst->z_i = -1.26;
		lst->z_r = 0;
	}

	lst->colormode = 1;
	lst->moove = 0;
	lst->iteration = 50;
	lst->x = 0;
	lst->y = 0;
	lst->zoom_x = WIN_SIZEX / (lst->x2 - lst->x1);
	lst->zoom_y = WIN_SIZEY / (lst->y2 - lst->y1);
	// ft_init_image(lst);
}

void	ft_mode(t_f *lst, char **av)
{
	if (av[1][0] == '1')
		lst->mode = 1;
	if (av[1][0] == '2')
		lst->mode = 2;
	if (av[1][0] == '3')
		lst->mode = 3;
	if (av[1][0] == '4')
		lst->mode = 4;
	if (av[1][0] == '5')
		lst->mode = 5;
	if (av[1][0] == '6')
		lst->mode = 6;
	if (av[1][0] == '7')
		lst->mode = 7;
	if (av[1][0] == '8')
		lst->mode = 8;
	ft_init_list(lst);
}
