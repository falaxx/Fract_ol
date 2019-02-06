/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:02:17 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/06 18:03:49 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_red(t_f *lst, int i)
{
	int x1;

	x1 = 0;
	if (lst->colormode == 1)
		x1 = sin(0.4 * i - 11) * 127 + 128;
	if (lst->colormode == 2)
		x1 = sin(0.1 * i + 12) * 127 + 128;
	if (lst->colormode == 3)
		x1 = sin(0.1 * i + 0) * 127 + 128;
	if (lst->colormode == 4)
		x1 = sin(0.3 * i + 0) * 127 + 128;
	if (lst->colormode == 5)
		x1 = sin(0.3 * i + 12) * 127 + 128;
	if (lst->colormode == 6)
		x1 = sin(0.5 * i + 0) * 127 + 128;
	if (lst->colormode == 7)
		x1 = sin(0.001 * i + 1) * 127 + 128;
	return (x1);
}

int		ft_green(t_f *lst, int i)
{
	int x2;

	x2 = 0;
	if (lst->colormode == 1)
		x2 = sin(0.1 * i + 33) * 127 + 128;
	if (lst->colormode == 2)
		x2 = sin(0.01 * i + 99) * 127 + 128;
	if (lst->colormode == 3)
		x2 = sin(0.9 * i + 48) * 127 + 128;
	if (lst->colormode == 4)
		x2 = sin(0.3 * i + 2) * 127 + 128;
	if (lst->colormode == 5)
		x2 = sin(0.2 * i + 5) * 127 + 128;
	if (lst->colormode == 6)
		x2 = sin(0.01 * i + 51) * 127 + 128;
	if (lst->colormode == 7)
		x2 = sin(0.3 * i + 9) * 127 + 128;
	return (x2);
}

int		ft_blue(t_f *lst, int i)
{
	int x3;

	x3 = 0;
	if (lst->colormode == 1)
		x3 = sin(0.22 * i + 12) * 127 + 128;
	if (lst->colormode == 2)
		x3 = sin(0.44 * i + 4) * 127 + 128;
	if (lst->colormode == 3)
		x3 = sin(0.7 * i - 22) * 127 + 128;
	if (lst->colormode == 4)
		x3 = sin(0.3 * i + 4) * 127 + 128;
	if (lst->colormode == 5)
		x3 = sin(0.3 * i + 10) * 127 + 128;
	if (lst->colormode == 6)
		x3 = sin(0.8 * i - 44) * 127 + 128;
	if (lst->colormode == 7)
		x3 = sin(0.044 * i + 8) * 127 + 128;
	return (x3);
}
