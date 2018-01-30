/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:25:25 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 20:33:22 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *dt, char direction)
{
	if (direction == 'z')
	{
		ft_putendl("zooming");
		dt->cf->x_zoom *= 0.66;
		dt->cf->y_zoom *= 0.66;
		dt->cf->x_move *= 0.66;
		dt->cf->y_move *= 0.66;
	}
	else
	{
		ft_putendl("un-zooming");
		dt->cf->x_zoom *= 1.33;
		dt->cf->y_zoom *= 1.33;
		dt->cf->x_move *= 1.33;
		dt->cf->y_move *= 1.33;
	}
}

void	mouse_center(t_data *dt, int x, int y)
{
	dt->cf->x_center += (x - dt->md->width / 2) * dt->cf->x_zoom;
	dt->cf->y_center += (y - dt->md->height / 2) * dt->cf->y_zoom;
}

int		mouse_hook(int bu, int x, int y, t_data *dt)
{
	ft_putnbr(bu);
	ft_putstr(" mouse		");
	// if (dt->cf->mode == 'z')
	// {
		mouse_center(dt, x, y);
		if (bu == 1 || bu == 4)
			zoom(dt, 'z');
		else
			zoom(dt, 'u');
	// }
	display(dt, dt->cf->fractal);
	return (0);
}
