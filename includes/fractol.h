/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:37:42 by fmerding          #+#    #+#             */
/*   Updated: 2019/02/05 18:16:01 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include <string.h>
# include <math.h>
# include <stdio.h>//attention
# include <pthread.h>
# define WIN_SIZEX 800
# define WIN_SIZEY 600


typedef struct		s_f
{
	int				savei;
	int				savej;
	int				iteration;
	int				mode;
	int				colormode;
	int				moove;
	double			z_i;
	double			z_r;
	double			x1;
	double 			x2;
	double			y1;
	double			y2;
	double			x;
	double			y;
	double			zoom_x;
	double			zoom_y;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	unsigned char	*s_img;
	int				xzoom;
	int				yzoom;

}					t_f;

typedef struct		s_th
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	int			i;
	int 		x;
	int 		y;
}				t_th;


void	ft_menu(t_f *lst);
void	ft_zoom(int x, int y, t_f *lst, int z);
void	ft_mode(t_f *lst, char **av);
int 	mouse_move (int x, int y, void *param);
float	ft_random7(void);
void	ft_init_image(t_f *lst);
int		key_hook(int key, void *param);
int		mouse_hook(int key, int i, int j, void *param);
int		ft_expose(void *param);
// void	ft_init_image_menu(t_f *lst);
void	ft_lightup_pixel(t_f *lst, int x, int y, int i);
// void 	ft_lightup_menu(t_f *lst);
void	ft_trace(t_f *lst);
void	ft_trace2(t_f *lst);
void	ft_trace3(t_f *lst);
void	ft_trace4(t_f *lst);
void	ft_trace5(t_f *lst);
void	ft_trace6(t_f *lst);
void	ft_trace7(t_f *lst);
void	ft_trace8(t_f *lst);
void	ft_init_list(t_f *lst);
void	ft_init_list2(t_f *lst);
void	ft_init_list3(t_f *lst);
void	ft_re_init_list(t_f *lst);
void	*ft_thread_2(void *arg);
void	*ft_thread_1(void *arg);


#endif
