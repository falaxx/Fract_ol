/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:34:00 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/07 18:25:26 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_trace2(t_f *lst)
{
	pthread_t thread[4];

	if (pthread_create(&thread[0], NULL, ft_thread_5, (void *)lst) == -1)
		exit(0);
	if (pthread_create(&thread[1], NULL, ft_thread_6, (void *)lst) == -1)
		exit(0);
	if (pthread_create(&thread[2], NULL, ft_thread_7, (void *)lst) == -1)
		exit(0);
	if (pthread_create(&thread[3], NULL, ft_thread_8, (void *)lst) == -1)
		exit(0);
	if (pthread_join(thread[0], NULL) == -1)
		exit(0);
	if (pthread_join(thread[1], NULL) == -1)
		exit(0);
	if (pthread_join(thread[2], NULL) == -1)
		exit(0);
	if (pthread_join(thread[3], NULL) == -1)
		exit(0);
}

void	*ft_thread_5(void *arg)
{
	t_th	*tread;
	int		i;
	t_f		*lst;

	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	lst = (t_f *)arg;
	tread->x = WIN_SIZEX / 2;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX / 8 * 5)
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

void	*ft_thread_6(void *arg)
{
	t_th	*tread;
	int		i;
	t_f		*lst;

	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	lst = (t_f *)arg;
	tread->x = WIN_SIZEX / 8 * 5;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX / 8 * 6)
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

void	*ft_thread_7(void *arg)
{
	t_th	*tread;
	int		i;
	t_f		*lst;

	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	lst = (t_f *)arg;
	tread->x = WIN_SIZEX / 8 * 6;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX / 8 * 7)
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

void	*ft_thread_8(void *arg)
{
	t_th	*tread;
	int		i;
	t_f		*lst;

	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	lst = (t_f *)arg;
	tread->x = WIN_SIZEX / 8 * 7;
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
