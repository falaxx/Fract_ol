
#include "fractol.h"

void ft_modetrace(t_f *lst)
{
	if (lst->mode == 2)
		ft_trace2(lst);
	if (lst->mode == 3)
		ft_trace3(lst);
	if (lst->mode == 4)
		ft_trace4(lst);
	if (lst->mode == 5)
		ft_trace5(lst);
	if (lst->mode == 6)
		ft_trace6(lst);
	if (lst->mode == 7)
		ft_trace7(lst);
	if (lst->mode == 8)
		ft_trace8(lst);
}

void	ft_trace(t_f *lst)
{

	pthread_t thread[2];

	if (lst->mode != 1)
	{
		ft_modetrace(lst);
		ft_menu(lst);
		return ;
	}
	if (pthread_create(&thread[0], NULL, ft_thread_1, (void *)lst) == -1)
		exit(0);
	if (pthread_create(&thread[1], NULL, ft_thread_2, (void *)lst) == -1)
		exit(0);
	if (pthread_join(thread[0], NULL) == -1)
		exit(0);
	if (pthread_join(thread[1], NULL) == -1)
		exit(0);
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
	ft_menu(lst);

}

void *ft_thread_1(void *arg)
{
	t_th *tread;
	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	int		i;
	t_f 	*lst;
	lst = (t_f *)arg;
	tread->x = 0;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX/2)
	{
		while (tread->y < WIN_SIZEY)
		{
			tread->c_r = tread->x / lst->zoom_x + lst->x1;
			tread->c_i = tread->y / lst->zoom_y + lst->y1;
			tread->z_r = lst->z_r;
			tread->z_i = lst->z_i;
			i = 0;
			while ((tread->z_r * tread->z_r + tread->z_i * tread->z_i) < 4 && i < lst->iteration)
			{
				tread->tmp = tread->z_r;
				tread->z_r = (tread->z_r * tread->z_r - tread->z_i * tread->z_i + tread->c_r);
				tread->z_i = (2 * tread->z_i * tread->tmp + tread->c_i);
				i++;
			}
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

void *ft_thread_2(void *arg)
{
	t_th *tread;
	if (!(tread = (t_th *)malloc(sizeof(t_th))))
		return (0);
	int		i;
	t_f 	*lst;
	lst = (t_f *)arg;
	tread->x = WIN_SIZEX/2;
	tread->y = 0;
	while (tread->x <= WIN_SIZEX)
	{
		while (tread->y < WIN_SIZEY)
		{
			tread->c_r = tread->x / lst->zoom_x + lst->x1;
			tread->c_i = tread->y / lst->zoom_y + lst->y1;
			tread->z_r = lst->z_r;
			tread->z_i = lst->z_i;
			i = 0;
			while ((tread->z_r * tread->z_r + tread->z_i * tread->z_i) < 4 && i < lst->iteration)
			{
				tread->tmp = tread->z_r;
				tread->z_r = (tread->z_r * tread->z_r - tread->z_i * tread->z_i + tread->c_r);
				tread->z_i = (2 * tread->z_i * tread->tmp + tread->c_i);
				i++;
			}
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



void	ft_trace2(t_f *lst)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	lst->x = 0;
	lst->y = 0;
	while (lst->x < WIN_SIZEX)
	{
		while(lst->y < WIN_SIZEY)
		{
			c_r = lst->z_r;
			c_i = lst->z_i;
			z_r = lst->x / lst->zoom_x + lst->x1;
			z_i = lst->y / lst->zoom_y + lst->y1;
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < lst->iteration)
			{
				tmp = z_r;
				z_r = (z_r * z_r - z_i * z_i + c_r);
				z_i = (2 * z_i * tmp + c_i);
				i++;
			}
			if (i == lst->iteration)
				ft_lightup_pixel(lst, lst->x, lst->y, 0);
			else
				ft_lightup_pixel(lst, lst->x, lst->y, i);
			lst->y++;
		}
		lst->y = 0;
		lst->x++;
	}
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
}
