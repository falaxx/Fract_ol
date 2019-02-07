/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:09:40 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/07 18:59:36 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook2(t_f *lst, int key)
{
	if (key == 67)
	{
		if (lst->moove == 1)
			lst->moove = 0;
		else
			lst->moove = 1;
	}
	if (key == 69)
	{
		if (lst->iteration >= 10)
			lst->iteration += 10;
		else if (lst->iteration < 10)
			lst->iteration++;
	}
	if (key == 78)
	{
		if (lst->iteration > 10)
			lst->iteration -= 10;
		else if (lst->iteration > 1)
			lst->iteration--;
	}
	if (key == 51)
		ft_init_list(lst);
	if (key == 53)
		exit(0);
}

void	key_hook3(t_f *lst, int key)
{
	if (key == 123)
	{
		lst->x1 -= 30 / lst->zoom_x;
		lst->x2 -= 30 / lst->zoom_x;
	}
	if (key == 124)
	{
		lst->x1 += 30 / lst->zoom_x;
		lst->x2 += 30 / lst->zoom_x;
	}
	if (key == 125)
	{
		lst->y1 += 30 / lst->zoom_y;
		lst->y2 += 30 / lst->zoom_y;
	}
	if (key == 126)
	{
		lst->y1 -= 30 / lst->zoom_y;
		lst->y2 -= 30 / lst->zoom_y;
	}
}

void	key_hook4(t_f *lst, int key)
{
	if (key == 18)
		lst->colormode = 1;
	if (key == 19)
		lst->colormode = 2;
	if (key == 20)
		lst->colormode = 3;
	if (key == 21)
		lst->colormode = 4;
	if (key == 22)
		lst->colormode = 5;
	if (key == 23)
		lst->colormode = 6;
	if (key == 26)
		lst->colormode = 7;
	if (key == 28)
	{
		if (lst->retarded == 0)
		{
			lst->retarded = 1;
			lst->colormode = ft_random7();
		}
		else
			lst->retarded = 0;
	}
}

int		key_hook(int key, void *param)
{
	t_f *lst;

	lst = (t_f *)param;
	if (key == 47)
	{
		lst->mode++;
		if (lst->mode == 9)
			lst->mode = 1;
		ft_init_list(lst);
	}
	if (key == 43)
	{
		lst->mode--;
		if (lst->mode == 0)
			lst->mode = 8;
		ft_init_list(lst);
	}
	key_hook2(lst, key);
	key_hook3(lst, key);
	key_hook4(lst, key);
	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst);
	ft_trace(lst);
	return (0);
}
