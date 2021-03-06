/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:15:15 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/04 11:30:00 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/wolf3d.h"
#include "../libft/includes/libft.h"

int	keycode_func(int keycode, int b)
{
	static int action = 0;
	
	if (b != RESET)
		return action;
	if (keycode == ESC)
		exit(0);
	else
		action = keycode;
	//ft_printf("%d is key touched\n", keycode);
	return (action);
}

int	mouse_func(int x, int y, int b)
{
	(void)b;
	(void)x;
	(void)y;
	return (1);
}
