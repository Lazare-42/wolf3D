/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:45:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/04 11:40:24 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define X_SIZE 500
# define Y_SIZE 500
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define ZOOM_IN 0.95
# define ZOOM_OUT 1.05
# define INIT_COLOR_DISTANCE 30
# define SPACE_BAR 49
# define ESC 53
# define PLUS 69
# define P 35
# define MINUS 78
# define M 46
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define MOVE_VIEW_LEFT 0
# define MOVE_VIEW_RIGHT 2
# define VIOLET 0x9370DB
# define CYAN	0x37FDFC
# define RESET 12131233

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*screen_data;
	int				keycode;
}					t_mlx;

typedef struct		s_map
{
	char			*map;
	int				line_size;
	int				map_height;
	int				player_pos;
	int				total_map_size;
}					t_map;

typedef struct		s_complx
{
	double			r;
	double			i;
	double			pos_offset;
}					t_complx;

typedef struct		s_info
{
	double			vectors[X_SIZE];
	t_map			map;
}					t_info;

int					mouse_zoom(int button, int x, int y, int b);
int					keycode_func(int keycode, int b);
int					mouse_func(int x, int y, int b);
t_mlx				set_get_mlx(t_mlx *mlx);
void				print_map(t_map map);
void    			print_vector_directions(t_info info);
t_map				place_player(t_map map);
t_map				read_map(void);
#endif
