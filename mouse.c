/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:25:25 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 15:26:04 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int button,int x,int y,t_data *dt)
{
	if (dt->cf->mode == 'z')
	{
		ft_putendl("zooming");
		dt->cf->x_center += (x - dt->md->width / 2) * dt->cf->x_zoom;
		dt->cf->y_center += (y - dt->md->height / 2) * dt->cf->y_zoom;
		dt->cf->x_zoom *= 0.66;
		dt->cf->y_zoom *= 0.66;
		dt->cf->x_move *= 0.66;
		dt->cf->y_move *= 0.66;
	}
	else if  (dt->cf->mode == 'p' && dt->cf->fractal == Julia)
	{
		ft_putendl("changing Julia parameters");
		dt->cf->x_Julia = (x - dt->md->width / 2.0) / dt->md->width * 2.0;
		dt->cf->y_Julia = (y - dt->md->height / 2.0) / dt->md->height * 2.0;
		printf("%.2f,%.2f\n",dt->cf->x_Julia,dt->cf->y_Julia);
	}
	display(dt, dt->cf->fractal);
	return (0);
}