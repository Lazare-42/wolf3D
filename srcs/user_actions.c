/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:15:15 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/03 18:21:31 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/wolf3d.h"
#include "../libft/includes/libft.h"

int	keycode_func(int keycode, int b)
{
	(void)b;
	if (keycode == ESC)
		(void)b;
	else if (keycode == SPACE_BAR)
		(void)b;
	else if (keycode == PLUS || keycode == P)
		(void)b;
	else if (keycode == MINUS || keycode == M)
		(void)b;
//	ft_printf("%d\n is key touched", keycode);
	return (1);
}

int	mouse_func(int x, int y, int b)
{
	(void)b;
	(void)x;
	(void)y;
	return (1);
}
