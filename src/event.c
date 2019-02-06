/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:15:39 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/06 17:15:51 by fmerding         ###   ########.fr       */
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
	// float xdiff = lst->x2-lst->x1;
	// float ydiff = lst->y2-lst->y1;

	if (z == 1)
	{
		lst->zoom_x *= 1.1;
		lst->zoom_y *= 1.1;
		lst->x1 = (lst->x1 * lst->zoom_x+ x - 0.5 * WIN_SIZEX) /
		lst->zoom_x;
		lst->x2 = (lst->x2 * lst->zoom_x+ x - 0.5 * WIN_SIZEX) /
		lst->zoom_x;
		lst->y1 = (lst->y1 * lst->zoom_y+ x - 0.5 * WIN_SIZEX) /
		lst->zoom_x;
		lst->y2 = (lst->y2 * lst->zoom_y+ x - 0.5 * WIN_SIZEX) /
		lst->zoom_x;
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
