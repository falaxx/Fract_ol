
#include "fractol.h"

void ft_trace(t_f *lst)
{
	float c_r;
	float c_i;
	float z_r;
	float z_i;
	float tmp;
	int i;

	lst->x = 0;
	lst->y = 0;
	while (lst->x < WIN_SIZEX)
	{
		while(lst->y < WIN_SIZEY)
		{
			c_r = lst->z_r ; // inverser pour mandel
			c_i = lst->z_i ;
			z_r = lst->x/lst->zoom_x + lst->x1;
			z_i = lst->y/lst->zoom_y + lst->y1;
			i = 0;

			while((z_r * z_r + z_i * z_i) < 4 && i < lst->iteration)
			{
				tmp = z_r;
				z_r = (z_r * z_r - z_i*z_i + c_r);
				z_i = (2 * z_i * tmp + c_i);
				i++;
			}
			if (i == lst->iteration)
				ft_lightup_pixel (lst, lst->x, lst->y, 0);
			else
				ft_lightup_pixel (lst, lst->x, lst->y, i);
			lst->y++;
		}
		lst->y = 0;
		lst->x++;
	}
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
}
