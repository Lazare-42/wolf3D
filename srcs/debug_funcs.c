/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:08:16 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/04 13:13:33 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../libft/includes/libft.h"

void	print_map(t_map map)
{
	int i;

	i = 0;
	while (map.map[i])
	{
		if (i % map.line_size == 0)
			ft_printf("\n");
		if (i != map.player_pos)
		{
			if (map.map[i] == 'X')
				ft_printf("[[green]]X[[end]]");
			else if (map.map[i] == '0')
				ft_printf("[[blue]]O[[end]]");
		}
		else
			ft_printf("[[red]]P[[end]]");
		i++;
	}
}
