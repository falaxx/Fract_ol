/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:24:58 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/06 18:32:20 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mode5(t_f *lst, t_th *tread, int i)
{
	tread->c_r = tread->x / lst->zoom_x + lst->x1;
	tread->c_i = lst->z_i;
	tread->z_r = lst->z_r;
	tread->z_i = tread->y / lst->zoom_y + lst->y1;
	i = 0;
	while (cos(tread->z_r * tread->z_r + tread->z_i * tread->z_i)
	< 0.99 && i < lst->iteration && (tread->z_r * tread->z_r + tread->z_i *
	tread->z_i) < 4)
	{
		tread->tmp = fabs(tread->z_r);
		tread->z_r = fabs(tread->z_r * tread->z_r - tread->z_i *
		tread->z_i + tread->c_r);
		tread->z_i = fabs(2 * tread->z_i * tread->tmp + tread->c_i);
		i++;
	}
	return (i);
}

int		ft_mode6(t_f *lst, t_th *tread, int i)
{
	tread->c_r = lst->z_i;
	tread->c_i = tread->x / lst->zoom_x + lst->x1;
	tread->z_r = tread->y / lst->zoom_y + lst->y1;
	tread->z_i = lst->z_r;
	i = 0;
	while (fabs(tread->z_r * tread->z_r + tread->z_i * tread->z_i)
	< 4 && i < lst->iteration)
	{
		tread->tmp = fabs(tread->z_r);
		tread->z_r = fabs(tread->z_r * tread->z_r - tread->z_i *
		tread->z_i + tread->c_r);
		tread->z_i = fabs(2 * tread->z_i * tread->tmp + tread->c_i);
		i++;
	}
	return (i);
}

int		ft_mode7(t_f *lst, t_th *tread, int i)
{
	tread->c_r = tread->x / lst->zoom_x + lst->x1;
	tread->c_i = lst->z_i / 4222;
	tread->z_r = tread->y / lst->zoom_y + lst->y1;
	tread->z_i = lst->z_r / 4222;
	i = 0;
	while (sqrt(tread->z_r * tread->z_r + tread->z_i * tread->z_i)
	> 0 && i < lst->iteration)
	{
		tread->tmp = (tread->z_r);
		tread->z_r = (tread->z_r * tread->z_r - tread->z_i *
		tread->z_i + tread->c_r);
		tread->z_i = (2 * tread->z_i * tread->tmp + tread->c_i);
		i++;
	}
	return (i);
}

int		ft_mode8(t_f *lst, t_th *tread, int i)
{
	tread->c_r = lst->z_i;
	tread->c_i = tread->x / lst->zoom_x + lst->x1;
	tread->z_r = tread->y / lst->zoom_y + lst->y1;
	tread->z_i = lst->z_r;
	i = 0;
	while (sqrt(tread->z_r * tread->z_r + tread->z_i * tread->z_i)
	> 0 && i < lst->iteration)
	{
		tread->tmp = tread->z_r;
		tread->z_r = (tread->z_r * tread->z_r - tread->z_i *
		tread->z_i + tread->c_r);
		tread->z_i = (2 * tread->z_i * tread->tmp + tread->c_i);
		i++;
	}
	return (i);
}
