
#include "fractol.h"

int		main()
{
	t_f	*lst;

	// if (ac != 2)
	// {
	// 	ft_putstr("usage : ./fractol source_file");
	// 	return (0);
	// }
	if (!(lst = (t_f *)malloc(sizeof(t_f))))
		return (0);
	ft_init_list(lst);
	ft_trace(lst);
	mlx_hook(lst->win_ptr, 2, 0, key_hook, (void *)lst);
	mlx_hook(lst->win_ptr, 4, 0, mouse_hook, (void *)lst);
	mlx_hook(lst->win_ptr, 6, 0, mouse_move, (void *)lst);
	mlx_hook(lst->win_ptr, 17, 0, ft_expose, (void *)lst);
	mlx_loop(lst->mlx_ptr);
	return (0);
}
