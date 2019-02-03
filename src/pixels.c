
#include "fractol.h"

void	ft_lightup_pixel(t_f *lst, int x, int y, int i)
{
	int new_x;
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	if (x < WIN_SIZEX && y < WIN_SIZEY && x > 0 && y > 0)
	{
		new_x = x * 4 + ((WIN_SIZEX * 4) * y);
		// if (i <= 10)
			x1 = i*255*0.0001*lst->iteration;
		// if ((i > 10 && i <= 20) || (i > 100 && i <= 200))
 		// 	x1= i*255*0.01*lst->iteration;
		// if ((i > 20 && i <= 30) || (i > 200 && i <= 300))
		// 	x1=i*255*0.1*lst->iteration;
		// if ((i > 30 && i <= 40) || (i > 300 && i <= 400))
		// 	x1 = i*255*0.001*lst->iteration;
		// if ((i > 40 && i <= 50) || (i > 400 && i <= 500))
		// 	x1= i*255*0.01*lst->iteration;
		// if ((i > 50 && i <= 60) || (i > 500 && i <= 600))
		// 	x1= i*255*0.1*lst->iteration;
		// if ((i > 60 && i <= 70) || (i > 600 && i <= 700))
		// 	x1 = i*255*0.001*lst->iteration;
		// if ((i > 70 && i <= 80) || (i > 700 && i <= 800))
		// 	x1= i*255*0.01*lst->iteration;
		// if ((i > 80 && i <= 90) || (i > 800 && i <= 900))
		// 	x1= i*255*0.1*lst->iteration;
		// if ((i > 90 && i <= 100)|| (i > 900 && i <= 1000))
		// 	x1 = i*255*0.0001*lst->iteration;
		lst->s_img[new_x] = x1;
		lst->s_img[new_x + 1] = x2;
		lst->s_img[new_x + 2] = x3;
		lst->s_img[new_x + 3] = 1;
	}
}


float		ft_random7(void)
{
	int random;

	random = rand() * 1;
	if (random < 268435455)
		return (0.1);
	else if (random < 268435455 * 2)
		return (0.2);
	else if (random < 268435455 * 3)
		return (0.3);
	else if (random < 268435455 * 4)
		return (0.4);
	else if (random < 268435455 * 5)
		return (0.5);
	else if (random < 268435455 * 6)
		return (0.6);
	else if (random < 268435455 * 7)
		return (0.7);
	else
		return (0.8);
}
