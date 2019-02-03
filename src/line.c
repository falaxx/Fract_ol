
#include "fdf.h"

void	ft_lineX(t_fdf *lst) //Rouge
{

	float tmp = 0;
	float d = 0;

	lst->i = 1;
	if (lst->xb < lst->xa)
	{
		ft_swap(&lst->xa, &lst->xb);
		ft_swap(&lst->ya, &lst->yb);
	}
	mlx_pixel_put (lst->mlx_ptr,lst->win_ptr, lst->xa, lst->ya, 0xFF5454);
	if (lst->ya > lst->yb)
		lst->i = -1;
	d = (lst->yb - lst->ya);
	d /= (lst->xb - lst->xa);
	tmp = lst->ya;
	while (lst->xa != lst->xb)
	{
		lst->xa++;
		tmp = tmp + d;
		if (d > 0)
		{
			if (tmp > lst->ya + 0.5)
				lst->ya += lst->i;
		}
		else
		{
			if (tmp < lst->ya - 0.5)
				lst->ya += lst->i;
		}
		mlx_pixel_put (lst->mlx_ptr,lst->win_ptr, lst->xa, lst->ya, 0xFF5454);
	}
}

void	ft_lineY(t_fdf *lst) //Vert
{

	float tmp = 0;
	float d = 0;

	lst->i = 1;

	if (lst->yb < lst->ya)
	{
		ft_swap(&lst->xa, &lst->xb);
		ft_swap(&lst->ya, &lst->yb);
	}
	mlx_pixel_put (lst->mlx_ptr,lst->win_ptr, lst->xa, lst->ya, 0x09FF00);

	if (lst->xa > lst->xb)
		lst->i = -1;
	d = (lst->xb - lst->xa);
	d /= (lst->yb - lst->ya);

	tmp = lst->xa;
	while (lst->ya != lst->yb)
	{
		lst->ya++;
		tmp = tmp + d;

		if (d > 0)
		{
			if (tmp > lst->xa + 0.5)
				lst->xa += lst->i;
		}
		else
		{
			if (tmp < lst->xa - 0.5)
				lst->xa += lst->i;
		}

		mlx_pixel_put (lst->mlx_ptr,lst->win_ptr, lst->xa, lst->ya, 0x09FF00);
	}
}

void	ft_trace(t_fdf *lst)
{
	lst->xa = 200;
	lst->ya = 200;
	lst->xb = 150;
	lst->yb = 50;

	if (ft_abs(lst->xa - lst->xb) > ft_abs(lst->ya - lst->yb))
		ft_lineX(lst);
	else
		ft_lineY(lst);
}
