/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:43:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/03 18:22:30 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/wolf3d.h"
#include "../minilibx_macos/mlx.h"

static int		loop_fractal(int necessary)
{
	(void)necessary;
//	fractal_handler();
	return (1);
}

static	t_mlx	my_mlx_init(void)
{
	t_mlx	mlx;
	int		bpp;
	int		endian;
	int		size_line;

	if (!(mlx.mlx = mlx_init()))
		ft_myexit("malloc error");
	if (!(mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "Fract'ol")))
		ft_myexit("malloc error");
	if (!(mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE)))
		ft_myexit("malloc error");
	if (!(mlx.screen_data = (int*)mlx_get_data_addr(mlx.image,
			&bpp, &size_line, &endian)))
		ft_myexit("malloc error");
	set_get_mlx(&mlx);
//	fractal_handler();
	return (mlx);
}

static int		draw(void)
{
	static	t_mlx	mlx;
	static	int		initalize = 0;

	if (!initalize)
	{
		mlx = my_mlx_init();
		initalize = 1;
	}
//	mlx_mouse_hook(mlx.win, mouse_zoom, 0);
	mlx_hook(mlx.win, KEYPRESS, KEYRELEASE, keycode_func, 0);
	mlx_hook(mlx.win, MOTIONNOTIFY, MOTIONNOTIFY, mouse_func, 0);
	mlx_loop_hook(mlx.mlx, loop_fractal, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

int main()
{
	draw();
}
