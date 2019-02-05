#include "fractol.h"

void ft_trace3(t_f *lst)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	lst->x = 0;
	lst->y = 0;
	while (lst->x < WIN_SIZEX)
	{
		while(lst->y < WIN_SIZEY)
		{
			c_r = lst->z_r;
			c_i = lst->y / lst->zoom_y + lst->y1;
			z_r = lst->x / lst->zoom_x + lst->x1;
			z_i = lst->z_i;
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < lst->iteration)
			{
				tmp = z_r;
				z_r = (z_r * z_r - z_i * z_i + c_r);
				z_i = (2 * z_i * tmp + c_i);
				i++;
			}
			if (i == lst->iteration)
				ft_lightup_pixel(lst, lst->x, lst->y, 0);
			else
				ft_lightup_pixel(lst, lst->x, lst->y, i);
			lst->y++;
		}
		lst->y = 0;
		lst->x++;
	}
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
}

void	ft_trace4(t_f *lst)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	lst->x = 0;
	lst->y = 0;
	while (lst->x < WIN_SIZEX)
	{
		while(lst->y < WIN_SIZEY)
		{
			c_r = lst->x / lst->zoom_x + lst->x1;
			c_i = lst->z_i;
			z_r = lst->z_r;
			z_i = lst->y / lst->zoom_y + lst->y1;
			i = 0;
			while (sin((z_r * z_r + z_i * z_i)) > 0.1  && i < lst->iteration && (z_r * z_r + z_i * z_i) < 4 && i < lst->iteration)
			{
				tmp = z_r;
				z_r = (z_r * z_r - z_i * z_i + c_r);
				z_i = (2 * z_i * tmp + c_i);
				i++;
			}
			if (i == lst->iteration)
				ft_lightup_pixel(lst, lst->x, lst->y, 0);
			else
				ft_lightup_pixel(lst, lst->x, lst->y, i);
			lst->y++;
		}
		lst->y = 0;
		lst->x++;
	}
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
}

void	ft_trace5(t_f *lst)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	lst->x = 0;
	lst->y = 0;
	while (lst->x < WIN_SIZEX)
	{
		while(lst->y < WIN_SIZEY)
		{
			c_r = lst->x / lst->zoom_x + lst->x1;
			c_i = lst->z_i;
			z_r = lst->z_r;
			z_i = lst->y / lst->zoom_y + lst->y1;
			i = 0;
			while (cos(z_r * z_r + z_i * z_i) < 0.99 && (z_r * z_r + z_i * z_i) < 4 && i < lst->iteration)
			{
				tmp = fabs(z_r);
				z_r = fabs(z_r * z_r - z_i * z_i + c_r);
				z_i = fabs(2 * z_i * tmp + c_i);
				i++;
			}
			if (i == lst->iteration)
				ft_lightup_pixel(lst, lst->x, lst->y, 0);
			else
				ft_lightup_pixel(lst, lst->x, lst->y, i);
			lst->y++;
		}
		lst->y = 0;
		lst->x++;
	}
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
}

void	ft_trace6(t_f *lst)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	lst->x = 0;
	lst->y = 0;
	while (lst->x < WIN_SIZEX)
	{
		while(lst->y < WIN_SIZEY)
		{
			c_r = lst->z_i;
			c_i = lst->x / lst->zoom_x + lst->x1;
			z_r = lst->y / lst->zoom_y + lst->y1;
			z_i = lst->z_r;
			i = 0;
			while (fabs(z_r * z_r + z_i * z_i) < 4 && i < lst->iteration)
			{
				tmp = fabs(z_r);
				z_r = fabs(z_r * z_r - z_i * z_i + c_r);
				z_i = fabs(2 * z_i * tmp + c_i);
				i++;
			}
			if (i == lst->iteration)
				ft_lightup_pixel(lst, lst->x, lst->y, 0);
			else
				ft_lightup_pixel(lst, lst->x, lst->y, i);
			lst->y++;
		}
		lst->y = 0;
		lst->x++;
	}
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
}

void	ft_trace7(t_f *lst)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	lst->x = 0;
	lst->y = 0;
	while (lst->x < WIN_SIZEX)
	{
		while(lst->y < WIN_SIZEY)
		{
			c_r = lst->x / lst->zoom_x + lst->x1;
			c_i = lst->z_i/4222;
			z_r = lst->y / lst->zoom_y + lst->y1;
			z_i = lst->z_r/4222;
			i = 0;
			while (sqrt(z_r * z_r + z_i * z_i) > 0 && i < lst->iteration)
			{
				tmp = (z_r);
				z_r = (z_r * z_r - z_i * z_i + c_r);
				z_i = (2 * z_i * tmp + c_i);
				i++;
			}
			if (i == lst->iteration)
				ft_lightup_pixel(lst, lst->x, lst->y, 0);
			else
				ft_lightup_pixel(lst, lst->x, lst->y, i);
			lst->y++;
		}
		lst->y = 0;
		lst->x++;
	}
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
}

void	ft_trace8(t_f *lst)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	lst->x = 0;
	lst->y = 0;
	while (lst->x < WIN_SIZEX)
	{
		while(lst->y < WIN_SIZEY)
		{
			c_r = lst->z_i;
			c_i = lst->x / lst->zoom_x + lst->x1;
			z_r = lst->y / lst->zoom_y + lst->y1;
			z_i = lst->z_r;
			i = 0;
			while (sqrt(z_r * z_r + z_i * z_i) > 0 && i < lst->iteration)
			{
				tmp = (z_r);
				z_r = (z_r * z_r - z_i * z_i + c_r);
				z_i = (2 * z_i * tmp + c_i);
				i++;
			}
			if (i == lst->iteration)
				ft_lightup_pixel(lst, lst->x, lst->y, 0);
			else
				ft_lightup_pixel(lst, lst->x, lst->y, i);
			lst->y++;
		}
		lst->y = 0;
		lst->x++;
	}
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
}
