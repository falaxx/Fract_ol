
#include "fractol.h"

void	ft_lightup_pixel(t_f *lst, int x, int y, int i)
{
	int new_x;

	if (x < WIN_SIZEX && y < WIN_SIZEY && x > 0 && y > 0)
	{
		new_x = x * 4 + ((WIN_SIZEX * 4) * y);
		lst->s_img[new_x] = i*255/lst->iteration;
		lst->s_img[new_x + 1] = 0;
		lst->s_img[new_x + 2] = 0;
		lst->s_img[new_x + 3] = 0;
	}
}


int		ft_random7(void)
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
		return (8);
}
