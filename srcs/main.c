/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:43:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/04 16:11:23 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/wolf3d.h"
#include "../minilibx_macos/mlx.h"
#include <math.h>

t_info	vector_angle(t_info info, int tilt);
double	distance_to_hit(t_info info, int vector_number);

t_info	move_player(t_info info)
{
	int movement;
	int pos;

	movement = keycode_func(0, 1);
	pos = info.map.player_pos;
	if (movement == RESET)
		return (info);
	if (movement == LEFT)
		if (pos - 1 >= 0 && info.map.map[pos - 1] != 'X' && (pos) % info.map.line_size)
			pos -= 1;
	if (movement == RIGHT)
		if (pos + 1 <= info.map.total_map_size && info.map.map[pos + 1] != 'X' && (pos + 1) % info.map.line_size)
			pos += 1;
	if (movement == UP)
		if (pos - info.map.line_size >= 0 && info.map.map[pos - info.map.line_size] != 'X')
			pos -= info.map.line_size;
	if (movement == DOWN)
		if (pos + info.map.line_size < info.map.total_map_size && info.map.map[pos + info.map.line_size] != 'X')
			pos += info.map.line_size;
	if (movement == MOVE_VIEW_LEFT)
		info = vector_angle(info, 1);
	if (movement == MOVE_VIEW_RIGHT)
		info = vector_angle(info, -1);
	info.map.player_pos = pos;
	keycode_func(RESET, RESET);
//	print_map(info.map);
//	distance_to_hit(info, X_SIZE / 2);
	return (info);
}

t_info	vector_angle(t_info info, int tilt)
{
	double 			i;
	double 			origin;
	static double 	increment_vec = 0;
	static double 	angle_tilt = 0;

	i = 0;
	if (tilt && tilt == 1)
		angle_tilt += 1;
	else if (tilt && tilt == -1)
		angle_tilt -= 1;

	if (angle_tilt == 48 || angle_tilt == -48)
		angle_tilt = 0;

	if (angle_tilt == 8)
		origin = 0;
	else if (angle_tilt == -16)
		origin = 0;
	else
		origin = (M_PI / 6 + angle_tilt * M_PI / 24);
	ft_printf("[[red]] angle_tilt[[end]] : %d\n", (int)angle_tilt);
	if (!increment_vec)
		increment_vec = (M_PI / 3) / (X_SIZE / 2);
	while (i < X_SIZE)
	{
		info.vectors[(int)i] = -tan(origin + (i * increment_vec));
		i++;
	}
	print_vector_directions(info);
	//printf("%f is vector direction in ys at pixel column : %d\n", (float)info.vectors[(int)0], 0);
	printf("%f  angles in radians / by M_PI at 0\n", (origin + 0 * increment_vec) / M_PI);
	printf("%f  angles in radians / by M_PI at 0\n", (origin + (i - 1) * increment_vec) / M_PI);
	return (info);
} 

double	distance_to_hit(t_info info, int vector_number)
{
	char 	cell;
	double	offset;
	double	opposite_side;
	//double	total_opposite_sides;

	offset = ceil(info.vectors[vector_number]); 
	cell = info.map.map[info.map.player_pos - (int)(offset + info.map.line_size)];
	
	opposite_side = (offset - info.vectors[vector_number]) * info.vectors[vector_number];
	return (offset);
}

void	wolf_handler(void)
{
	static int		load_map = 0;
	static t_info	info;
	static t_mlx	mlx;

	if (!load_map)
	{
		mlx = set_get_mlx(NULL);
		info.map = read_map();
		info = vector_angle(info, 0);
		load_map = 1;
	}
	info = move_player(info);
}

static int		loop_wolf(int necessary)
{
	(void)necessary;
	wolf_handler();
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
	if (!(mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "Wolf3d")))
		ft_myexit("malloc error");
	if (!(mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE)))
		ft_myexit("malloc error");
	if (!(mlx.screen_data = (int*)mlx_get_data_addr(mlx.image,
			&bpp, &size_line, &endian)))
		ft_myexit("malloc error");
	set_get_mlx(&mlx);
	wolf_handler();
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
	mlx_hook(mlx.win, KEYPRESS, KEYRELEASE, keycode_func, (void*)RESET);
	//mlx_hook(mlx.win, MOTIONNOTIFY, MOTIONNOTIFY, mouse_func, 0);
	mlx_loop_hook(mlx.mlx, loop_wolf, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

int main()
{
	draw();
}
