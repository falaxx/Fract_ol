/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:46:51 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/07 19:23:00 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_menu(t_f *lst)
{
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 785, 0, 0xFFFFFF,
		"COMMANDS");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 12, 0xFFFFFF,
		" Arrows | Movements");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 24, 0xFFFFFF,
		" Delete | Reset");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 36, 0xFFFFFF,
		" Scroll | Zoom");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 48, 0xFFFFFF,
		" Escape | Close");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 60, 0xFFFFFF,
		"    8   | Random Colors");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 72, 0xFFFFFF,
		"   +/-  | Iterations");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 84, 0xFFFFFF,
		"   1-7  | Colors");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 96, 0xFFFFFF,
		"    *   | Block/Unblock");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 755, 108, 0xFFFFFF,
		"   ,/.  | Previous/Next");
}

void	ft_lightup_pixel(t_f *lst, int x, int y, int i)
{
	int new_x;
	int x1;
	int x2;
	int x3;

	if (x < WIN_SIZEX && y < WIN_SIZEY && x >= 0 && y >= 0)
	{
		new_x = x * 4 + ((WIN_SIZEX * 4) * y);
		x1 = ft_red(lst, i);
		x2 = ft_green(lst, i);
		x3 = ft_blue(lst, i);
		lst->s_img[new_x] = x1;
		lst->s_img[new_x + 1] = x2;
		lst->s_img[new_x + 2] = x3;
		lst->s_img[new_x + 3] = 0;
	}
}

void	ft_init_image(t_f *lst)
{
	int sizex;
	int sizey;
	int	bpp;
	int endian;

	sizex = WIN_SIZEX;
	sizey = WIN_SIZEY;
	bpp = 4;
	endian = 0;
	if (lst->retarded > 0)
	{
		lst->retarded++;
		if (lst->retarded % 10 == 0)
			lst->colormode = ft_random7();
	}
	lst->img = mlx_new_image(lst->mlx_ptr, sizex, sizey);
	lst->s_img = (unsigned char*)(mlx_get_data_addr(lst->img, &(bpp)
	, &(sizex), &(endian)));
}

float	ft_random7(void)
{
	int random;

	random = rand() * 1;
	if (random < 268435455)
		return (1);
	else if (random < 268435455 * 2)
		return (2);
	else if (random < 268435455 * 3)
		return (3);
	else if (random < 268435455 * 4)
		return (4);
	else if (random < 268435455 * 5)
		return (5);
	else if (random < 268435455 * 6)
		return (6);
	else if (random < 268435455 * 7)
		return (7);
	else
		return (4);
}
