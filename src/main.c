
#include "fractol.h"

int		main(int ac, char **av)
{
	t_f	*lst;

	if (ac != 2)
	{
		ft_putstr("usage : ./fractol #number");
		return (0);
	}
	if ((ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 3) || ft_strlen(av[1]) != 1)
	{
		ft_putstr("usage : ./fractol #numberbetween1and3");
		return (0);
	}
	if (!(lst = (t_f *)malloc(sizeof(t_f))))
		return (0);
	ft_mode(lst, av);
	ft_trace(lst);
	mlx_hook(lst->win_ptr, 2, 0, key_hook, (void *)lst);
	mlx_hook(lst->win_ptr, 4, 0, mouse_hook, (void *)lst);
	mlx_hook(lst->win_ptr, 6, 0, mouse_move, (void *)lst);
	mlx_hook(lst->win_ptr, 17, 0, ft_expose, (void *)lst);
	mlx_loop(lst->mlx_ptr);
	return (0);
}
