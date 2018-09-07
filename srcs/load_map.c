#include "../includes/wolf3d.h"
#include "../libft/includes/libft.h"
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
	ft_myexit("could not place player. Your map is invalid");
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
