/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:43:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/04 13:12:56 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/wolf3d.h"
#include "../minilibx_macos/mlx.h"
#include <fcntl.h>
#include <unistd.h>

t_map	place_player(t_map map)
{
	int i;

	i = map.total_map_size;
	while (i >= 0)
	{
		if (map.map[i] == '0')
		{
			map.player_pos = i;
			return (map);
		}
		i--;
	}
	print_map(map);
	ft_myexit("could not place player. Your map is invalid");
	return (map);
}

t_map	move_player(t_map map)
{
	int movement;
	int pos;

	movement = keycode_func(0, 1);
	pos = map.player_pos;
	if (!(movement))
		return (map);
	if (movement == LEFT)
		if (pos - 1 >= 0 && map.map[pos - 1] != 'X' && (pos) % map.line_size)
			pos -= 1;
	if (movement == RIGHT)
		if (pos + 1 <= map.total_map_size && map.map[pos + 1] != 'X' && (pos + 1) % map.line_size)
			pos += 1;
	if (movement == UP)
		if (pos - map.line_size >= 0 && map.map[pos - map.line_size] != 'X')
			pos -= map.line_size;
	if (movement == DOWN)
		if (pos + map.line_size <= map.total_map_size && map.map[pos + map.line_size] != 'X')
			pos += map.line_size;
	map.player_pos = pos;
	print_map(map);
	keycode_func(0, RESET);
	return (map);
}

t_map	read_map(void)
{
	int		fd;
	char	*buf;
	t_map	map;
	int		ret;

	buf = NULL;
	ret = 0;
	map.map = NULL;
	map.line_size = 0;
	fd = open("/Users/lazrossi/Documents/42/wolf3D/map.txt", O_RDONLY);
	ret = get_next_line(fd, &buf, '\n');
	if (ret >= 1)
		map.line_size = ft_strlen(buf);
	map.map_height = 0;
	while (ret >= 1)
	{
		map.map = ft_strjoinfree(&(map.map), &buf, 'B');
		map.map_height += 1;
		ret = get_next_line(fd, &buf, '\n');
	}
	map.total_map_size = map.map_height * map.line_size;
	close(fd);
	if (ret < 0)
		ft_myexit("error in get_next_line");
	return (map = place_player(map));
}

void	wolf_handler(void)
{
	static int		load_map = 0;
	static t_map	map;
	static t_mlx	mlx;

	if (!load_map)
	{
		map = read_map();
		load_map = 1;
	}
	map = move_player(map);
	mlx = set_get_mlx(NULL);
}

static int		loop_fractal(int necessary)
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
	if (!(mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "Fract'ol")))
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
	mlx_hook(mlx.win, KEYPRESS, KEYRELEASE, keycode_func, 0);
	//mlx_hook(mlx.win, MOTIONNOTIFY, MOTIONNOTIFY, mouse_func, 0);
	mlx_loop_hook(mlx.mlx, loop_fractal, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

int main()
{
	draw();
}
