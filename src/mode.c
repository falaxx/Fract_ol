/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:31:39 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/06 18:31:55 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mode(t_f *lst, t_th *tread, int i)
{
	if (lst->mode == 1)
		i = ft_mode1(lst, tread, i);
	if (lst->mode == 2)
		i = ft_mode2(lst, tread, i);
	if (lst->mode == 3)
		i = ft_mode3(lst, tread, i);
	if (lst->mode == 4)
		i = ft_mode4(lst, tread, i);
	if (lst->mode == 5)
		i = ft_mode5(lst, tread, i);
	if (lst->mode == 6)
		i = ft_mode6(lst, tread, i);
	if (lst->mode == 7)
		i = ft_mode7(lst, tread, i);
	if (lst->mode == 8)
		i = ft_mode8(lst, tread, i);
	return (i);
}

int		ft_mode1(t_f *lst, t_th *tread, int i)
{
	tread->c_r = tread->x / lst->zoom_x + lst->x1;
	tread->c_i = tread->y / lst->zoom_y + lst->y1;
	tread->z_r = lst->z_r;
	tread->z_i = lst->z_i;
	i = 0;
	while ((tread->z_r * tread->z_r + tread->z_i * tread->z_i)
	< 4 && i < lst->iteration)
	{
		tread->tmp = tread->z_r;
		tread->z_r = (tread->z_r * tread->z_r - tread->z_i *
		tread->z_i + tread->c_r);
		tread->z_i = (2 * tread->z_i * tread->tmp + tread->c_i);
		i++;
	}
	return (i);
}

int		ft_mode2(t_f *lst, t_th *tread, int i)
{
	tread->c_r = lst->z_r;
	tread->c_i = lst->z_i;
	tread->z_r = tread->x / lst->zoom_x + lst->x1;
	tread->z_i = tread->y / lst->zoom_y + lst->y1;
	i = 0;
	while ((tread->z_r * tread->z_r + tread->z_i * tread->z_i)
	< 4 && i < lst->iteration)
	{
		tread->tmp = tread->z_r;
		tread->z_r = (tread->z_r * tread->z_r - tread->z_i *
		tread->z_i + tread->c_r);
		tread->z_i = (2 * tread->z_i * tread->tmp + tread->c_i);
		i++;
	}
	return (i);
}

int		ft_mode3(t_f *lst, t_th *tread, int i)
{
	tread->c_r = lst->z_r;
	tread->c_i = tread->y / lst->zoom_y + lst->y1;
	tread->z_r = tread->x / lst->zoom_x + lst->x1;
	tread->z_i = lst->z_i;
	i = 0;
	while ((tread->z_r * tread->z_r + tread->z_i * tread->z_i)
	< 4 && i < lst->iteration)
	{
		tread->tmp = tread->z_r;
		tread->z_r = (tread->z_r * tread->z_r - tread->z_i *
		tread->z_i + tread->c_r);
		tread->z_i = (2 * tread->z_i * tread->tmp + tread->c_i);
		i++;
	}
	return (i);
}

int		ft_mode4(t_f *lst, t_th *tread, int i)
{
	tread->c_r = tread->x / lst->zoom_x + lst->x1;
	tread->c_i = lst->z_i;
	tread->z_r = lst->z_r;
	tread->z_i = tread->y / lst->zoom_y + lst->y1;
	i = 0;
	while (sin(tread->z_r * tread->z_r + tread->z_i * tread->z_i)
	> 0.1 && i < lst->iteration && (tread->z_r * tread->z_r + tread->z_i *
	tread->z_i) < 4)
	{
		tread->tmp = tread->z_r;
		tread->z_r = (tread->z_r * tread->z_r - tread->z_i *
		tread->z_i + tread->c_r);
		tread->z_i = (2 * tread->z_i * tread->tmp + tread->c_i);
		i++;
	}
	return (i);
}
