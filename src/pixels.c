
#include "fractol.h"

void	ft_menu(t_f *lst)
{
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 5, 0, 0xFFFFFF,
		"COMMANDS");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 5, 20, 0xFFFFFF,
		"Arrows | Movements");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 5, 35, 0xFFFFFF,
		"  + -  | Iterations");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 5, 50, 0xFFFFFF,
		"Scroll | Zoom");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 5, 65, 0xFFFFFF,
		" 1 2 3 | Colors");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 5, 80, 0xFFFFFF,
		"Delete | Reset");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 5, 95, 0xFFFFFF,
		"Escape | Close");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 5, 110, 0xFFFFFF,
		"   *   | block/unblock");
}


void	ft_lightup_pixel(t_f *lst, int x, int y, int i)
{
	int new_x;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	if (x < WIN_SIZEX && y < WIN_SIZEY && x > 0 && y > 0)
	{
		new_x = x * 4 + ((WIN_SIZEX * 4) * y);
		if (lst->colormode == 1)
		{
			x1 = sin(0.4*i - 11)*127+128;
			x2 = sin(0.1*i + 33)*127+128;
			x3 = sin(0.22*i + 12)*127+128;
		}
		if (lst->colormode == 2)
		{
			x1 = sin(0.1*i + 12)*127+128;
			x2 = sin(0.01*i + 99)*127+128;
			x3 = sin(0.44*i + 4)*127+128;
		}
		if (lst->colormode == 3)
		{
			x1 = sin(0.1*i + 0)*127+128;
			x2 = sin(0.9*i + 48)*127+128;
			x3 = sin(0.7*i - 22)*127+128;
		}
		if (lst->colormode == 4)
		{
			x1 = sin(0.3*i + 0)*127+128;
			x2 = sin(0.3*i + 2)*127+128;
			x3 = sin(0.3*i + 4)*127+128;
		}
		if (lst->colormode == 5)
		{
			x1 = sin(0.3*i + 12)*127+128;
			x2 = sin(0.2*i + 5)*127+128;
			x3 = sin(0.3*i + 10)*127+128;
		}
		if (lst->colormode == 6)
		{
			x1 = sin(0.5*i + 0)*127+128;
			x2 = sin(0.01*i + 51)*127+128;
			x3 = sin(0.8*i -44)*127+128;
		}
		if (lst->colormode == 7)
		{
			x1 = sin(0.001*i + 1)*127+128;
			x2 = sin(0.3*i + 9)*127+128;
			x3 = sin(0.044*i + 8)*127+128;
		}
		lst->s_img[new_x] = x1;
		lst->s_img[new_x + 1] = x2;
		lst->s_img[new_x + 2] = x3;
		lst->s_img[new_x + 3] = 0;
	}

}




float		ft_random7(void)
{
	int random;

	random = rand() * 1;
	if (random < 268435455)
		return (0.1);
	else if (random < 268435455 * 2)
		return (0.2);
	else if (random < 268435455 * 3)
		return (0.3);
	else if (random < 268435455 * 4)
		return (0.4);
	else if (random < 268435455 * 5)
		return (0.5);
	else if (random < 268435455 * 6)
		return (0.6);
	else if (random < 268435455 * 7)
		return (0.7);
	else
		return (0.8);
}
