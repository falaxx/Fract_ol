/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:02:19 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/07 18:20:08 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst);
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
		mlx_destroy_image(lst->mlx_ptr, lst->img);
		ft_init_image(lst);
		ft_trace(lst);
		lst->savei = x;
		lst->savej = y;
	}
	return (0);
}

void	ft_zoom(int x, int y, t_f *lst, int z)
{
	x = y;
	if (z == 1)
	{
		lst->zoom_x *= 1.1;
		lst->zoom_y *= 1.1;
	}
	if (z == 0)
	{
		lst->zoom_x /= 1.1;
		lst->zoom_y /= 1.1;
	}
}

int		ft_expose(void *param)
{
	t_f *lst;

	lst = (t_f *)param;
	exit(0);
}
