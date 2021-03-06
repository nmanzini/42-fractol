/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:25:25 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/31 17:39:49 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *dt, char direction)
{
	if (direction == 'z' && dt->cf->x_zoom > 0.00001)
	{
		ft_putendl("zooming");
		dt->cf->x_zoom *= 0.8;
		dt->cf->y_zoom *= 0.8;
		dt->cf->x_move *= 0.8;
		dt->cf->y_move *= 0.8;
	}
	else if (direction == 'u' && dt->cf->x_zoom < 10000)
	{
		ft_putendl("un-zooming");
		dt->cf->x_zoom *= 1.2;
		dt->cf->y_zoom *= 1.2;
		dt->cf->x_move *= 1.2;
		dt->cf->y_move *= 1.2;
	}
	else
		ft_putendl("stoped zoomig");
}

void	mouse_center(t_data *dt, int x, int y)
{
	dt->cf->x_center += (x - dt->md->width / 2) * dt->cf->x_zoom;
	dt->cf->y_center += (y - dt->md->height / 2) * dt->cf->y_zoom;
}

int		mouse_hook(int bu, int x, int y, t_data *dt)
{
	dt->cf->max_iter = dt->cf->max_iter_original;
	ft_putnbr(bu);
	ft_putstr(" mouse		");
	mouse_center(dt, x, y);
	if (bu == 1 || bu == 4)
		zoom(dt, 'z');
	else
		zoom(dt, 'u');
	display(dt, dt->cf->fractal);
	return (0);
}
