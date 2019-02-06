/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:35:41 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/06 18:35:44 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_trace(t_f *lst)
{
	pthread_t thread[4];

	if (pthread_create(&thread[0], NULL, ft_thread_1, (void *)lst) == -1)
		exit(0);
	if (pthread_create(&thread[1], NULL, ft_thread_2, (void *)lst) == -1)
		exit(0);
	if (pthread_create(&thread[2], NULL, ft_thread_3, (void *)lst) == -1)
		exit(0);
	if (pthread_create(&thread[3], NULL, ft_thread_4, (void *)lst) == -1)
		exit(0);
	if (pthread_join(thread[0], NULL) == -1)
		exit(0);
	if (pthread_join(thread[1], NULL) == -1)
		exit(0);
	if (pthread_join(thread[2], NULL) == -1)
		exit(0);
	if (pthread_join(thread[3], NULL) == -1)
		exit(0);
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
	ft_menu(lst);
}

void	*ft_thread_1(void *arg)
{
	t_th	*tread;
	int		i;
	t_f		*lst;

	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	lst = (t_f *)arg;
	tread->x = 0;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX / 4)
	{
		while (tread->y < WIN_SIZEY)
		{
			i = ft_mode(lst, tread, i);
			if (i == lst->iteration)
				ft_lightup_pixel(lst, tread->x, tread->y, 0);
			else
				ft_lightup_pixel(lst, tread->x, tread->y, i);
			tread->y++;
		}
		tread->y = 0;
		tread->x++;
	}
	free(tread);
	pthread_exit(NULL);
}

void	*ft_thread_2(void *arg)
{
	t_th	*tread;
	int		i;
	t_f		*lst;

	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	lst = (t_f *)arg;
	tread->x = WIN_SIZEX / 4;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX / 2)
	{
		while (tread->y < WIN_SIZEY)
		{
			i = ft_mode(lst, tread, i);
			if (i == lst->iteration)
				ft_lightup_pixel(lst, tread->x, tread->y, 0);
			else
				ft_lightup_pixel(lst, tread->x, tread->y, i);
			tread->y++;
		}
		tread->y = 0;
		tread->x++;
	}
	free(tread);
	pthread_exit(NULL);
}

void	*ft_thread_3(void *arg)
{
	t_th	*tread;
	int		i;
	t_f		*lst;

	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	lst = (t_f *)arg;
	tread->x = WIN_SIZEX / 2;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX / 4 * 3)
	{
		while (tread->y < WIN_SIZEY)
		{
			i = ft_mode(lst, tread, i);
			if (i == lst->iteration)
				ft_lightup_pixel(lst, tread->x, tread->y, 0);
			else
				ft_lightup_pixel(lst, tread->x, tread->y, i);
			tread->y++;
		}
		tread->y = 0;
		tread->x++;
	}
	free(tread);
	pthread_exit(NULL);
}

void	*ft_thread_4(void *arg)
{
	t_th	*tread;
	int		i;
	t_f		*lst;

	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	lst = (t_f *)arg;
	tread->x = WIN_SIZEX / 4 * 3;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX)
	{
		while (tread->y < WIN_SIZEY)
		{
			i = ft_mode(lst, tread, i);
			if (i == lst->iteration)
				ft_lightup_pixel(lst, tread->x, tread->y, 0);
			else
				ft_lightup_pixel(lst, tread->x, tread->y, i);
			tread->y++;
		}
		tread->y = 0;
		tread->x++;
	}
	free(tread);
	pthread_exit(NULL);
}
