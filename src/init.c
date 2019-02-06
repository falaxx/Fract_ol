/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:56:10 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/06 17:20:31 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_list3(t_f *lst)
{
	if (lst->mode == 5)
	{
		lst->x1 = -2;
		lst->x2 = -0.2;
		lst->y1 = -0.2;
		lst->y2 = 0.4;
		lst->z_i = -0.33;
		lst->z_r = -1.444;
		lst->colormode = 5;
	}
	if (lst->mode == 6)
	{
		lst->x1 = -2.3;
		lst->x2 = -0.2;
		lst->y1 = -0.55;
		lst->y2 = 0.55;
		lst->z_i = 0.96;
		lst->z_r = -0.35;
		lst->colormode = 6;
	}
}

void	ft_init_list4(t_f *lst)
{
	if (lst->mode == 7)
	{
		lst->x1 = -8;
		lst->x2 = 1;
		lst->y1 = -3;
		lst->y2 = 3;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
		lst->colormode = 7;
	}
	if (lst->mode == 8)
	{
		lst->x1 = -1;
		lst->x2 = 1;
		lst->y1 = -1.8;
		lst->y2 = 1.8;
		lst->z_i = -1.26;
		lst->z_r = 0;
		lst->colormode = 4;
	}
}

void	ft_init_list2(t_f *lst)
{
	if (lst->mode == 3)
	{
		lst->x1 = -1.7;
		lst->x2 = 1.7;
		lst->y1 = -1.2;
		lst->y2 = 1.2;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
		lst->colormode = 3;
	}
	if (lst->mode == 4)
	{
		lst->x1 = -1.7;
		lst->x2 = 1.2;
		lst->y1 = -1.4;
		lst->y2 = 0.4;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
		lst->colormode = 4;
	}
}

void	ft_init_list0(t_f *lst)
{
	if (lst->mode == 2)
	{
		lst->x1 = -1.5;
		lst->x2 = 1.5;
		lst->y1 = -1.2;
		lst->y2 = 1.2;
		lst->z_i = -0.62;
		lst->z_r = -0.62;
		lst->colormode = 2;
	}
	ft_init_list2(lst);
	ft_init_list3(lst);
	ft_init_list4(lst);
	lst->iteration = 100;
	lst->x = 0;
	lst->y = 0;
	lst->zoom_x = WIN_SIZEX / (lst->x2 - lst->x1);
	lst->zoom_y = WIN_SIZEY / (lst->y2 - lst->y1);
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
		lst->colormode = 1;
	}
	ft_init_list0(lst);
}
