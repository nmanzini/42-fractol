/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:17:43 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 15:23:06 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	Mandelbrot(t_data *dt)
{
	int Px;
	int Py;
	float x0;
	float y0;
	int iter;
	float x;
	float x_temp;
	float y;

	Px = -1;
	while (++Px < dt->md->width)
	{
		Py = -1;
		while (++Py < dt->md->height)
		{
			x0 = Px - dt->md->width / 2.0;
			y0 = Py - dt->md->height / 2.0;
			x0 = x0 / (float)dt->md->width * dt->cf->x_zoom; 
			y0 = y0 / (float)dt->md->height * dt->cf->y_zoom;
			x0 = x0 + dt->cf->x_center / (float)dt->md->width;
			y0 = y0 + dt->cf->y_center / (float)dt->md->height;
			x = 0.0;
			y = 0.0;
			iter = 0;
			while (x * x + y * y < 4 && iter < dt->cf->max_iter)
			{
				x_temp = x * x - y * y + x0;
				y = 2 * x * y + y0;
				x = x_temp;
				iter++;
			}
			fractal_color(dt, Px, Py, iter );
		}
	}
}

void	Julia(t_data *dt)
{
	int Px;
	int Py;
	float x0;
	float y0;
	int iter;
	float x;
	float x_temp;
	float y;

	Px = -1;
	while (++Px < dt->md->width)
	{
		Py = -1;
		while (++Py < dt->md->height)
		{
			x0 = dt->cf->x_Julia;
			y0 = dt->cf->y_Julia;
			x = Px - dt->md->width / 2.0;
			y = Py - dt->md->height / 2.0;
			x = x / (float)dt->md->width * dt->cf->x_zoom; 
			y = y / (float)dt->md->height * dt->cf->y_zoom;
			x = x + dt->cf->x_center / (float)dt->md->width;
			y = y + dt->cf->y_center / (float)dt->md->height;
			iter = 0;
			while (x * x + y * y < 4  &&  iter < dt->cf->max_iter) 
			{
				x_temp = x * x - y * y;
				y = 2 * x * y + y0;
				x = x_temp + x0;
				iter++;
			}
			fractal_color(dt, Px, Py, iter );
		}
	}
}

void 	Tricorn(t_data *dt)
{
	int Px;
	int Py;
	float x0;
	float y0;
	int iter;
	float x;
	float x_temp;
	float y;

	Px = -1;
	while (++Px < dt->md->width)
	{
		Py = -1;
		while (++Py < dt->md->height)
		{
			x0 = Px - dt->md->width / 2.0;
			y0 = Py - dt->md->height / 2.0;
			x0 = x0 / (float)dt->md->width * dt->cf->x_zoom; 
			y0 = y0 / (float)dt->md->height * dt->cf->y_zoom;
			x0 = x0 + dt->cf->x_center / (float)dt->md->width;
			y0 = y0 + dt->cf->y_center / (float)dt->md->height;
			x = 0.0;
			y = 0.0;
			iter = 0;
			while (x * x + y * y < 4 && iter < dt->cf->max_iter)
			{
				x_temp = x * x - y * y + x0;
				y = - 2 * x * y + y0;
				x = x_temp;
				iter++;
			}
			fractal_color(dt, Px, Py, iter );
		}
	}
}

void 	Burning_ship(t_data *dt)
{
	int Px;
	int Py;
	float x0;
	float y0;
	int iter;
	float x;
	float x_temp;
	float y;

	Px = -1;
	while (++Px < dt->md->width)
	{
		Py = -1;
		while (++Py < dt->md->height)
		{
			x0 = Px - dt->md->width / 2.0;
			y0 = Py - dt->md->height / 2.0;
			x0 = x0 / (float)dt->md->width * dt->cf->x_zoom; 
			y0 = y0 / (float)dt->md->height * dt->cf->y_zoom;
			x0 = x0 + dt->cf->x_center / (float)dt->md->width;
			y0 = y0 + dt->cf->y_center / (float)dt->md->height;
			x = 0.0;
			y = 0.0;
			iter = 0;

			while (x * x + y * y < 4 && iter < dt->cf->max_iter)
			{
				x_temp = x * x - y * y + x0;
				y = float_abs(2 * x * y + y0);
				x = float_abs(x_temp);
				iter++;
			}
			fractal_color(dt, Px, Py, iter );
		}
	}
}
