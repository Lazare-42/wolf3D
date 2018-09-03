/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:09:58 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/03 18:11:22 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/wolf3d.h"

t_mlx	set_get_mlx(t_mlx *mlx)
{
	static t_mlx mlx_linker;

	if (mlx)
		mlx_linker = *mlx;
	return (mlx_linker);
}

t_complx	set_get_mouse_pos(double x, double y)
{
	static t_complx mouse_pos;

	if (x && y)
	{
		mouse_pos.r = x;
		mouse_pos.i = y;
	}
	return (mouse_pos);
}
