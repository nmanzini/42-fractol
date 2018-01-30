/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:17:43 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 18:08:08 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_pi_p0_iter(t_data *dt, int *pi, float *p0, int *iter)
{
	p0[0] = pi[0] - dt->md->width / 2.0;
	p0[1] = pi[1] - dt->md->height / 2.0;
	p0[0] = p0[0] / (float)dt->md->width * dt->cf->x_zoom;
	p0[1] = p0[1] / (float)dt->md->height * dt->cf->y_zoom;
	p0[0] = p0[0] + dt->cf->x_center / (float)dt->md->width;
	p0[1] = p0[1] + dt->cf->y_center / (float)dt->md->height;
	*iter = -1;
}

void	mandelbrot(t_data *dt)
{
	int		pi[2];
	float	p0[2];
	float	p[2];
	int		iter;
	float	x_temp;

	pi[0] = -1;
	while (++(pi[0]) < dt->md->width)
	{
		pi[1] = -1;
		while (++(pi[1]) < dt->md->height)
		{
			setup_pi_p0_iter(dt, pi, p0, &iter);
			p[0] = 0.0;
			p[1] = 0.0;
			while (p[0] * p[0] + p[1] * p[1] < 4 && ++iter < dt->cf->max_iter)
			{
				x_temp = p[0] * p[0] - p[1] * p[1] + p0[0];
				p[1] = 2 * p[0] * p[1] + p0[1];
				p[0] = x_temp;
			}
			fractal_color(dt, pi[0], pi[1], iter);
		}
	}
}

void	julia(t_data *dt)
{
	int		pi[2];
	float	p0[2];
	float	p[2];
	int		iter;
	float	x_temp;

	pi[0] = -1;
	while (++(pi[0]) < dt->md->width)
	{
		pi[1] = -1;
		while (++(pi[1]) < dt->md->height)
		{
			setup_pi_p0_iter(dt, pi, p, &iter);
			p0[0] = dt->cf->x_Julia;
			p0[1] = dt->cf->y_Julia;
			while (p[0] * p[0] + p[1] * p[1] < 4 && ++iter < dt->cf->max_iter)
			{
				x_temp = p[0] * p[0] - p[1] * p[1];
				p[1] = 2 * p[0] * p[1] + p0[1];
				p[0] = x_temp + p0[0];
			}
			fractal_color(dt, pi[0], pi[1], iter);
		}
	}
}

void	burning_ship(t_data *dt)
{
	int		pi[2];
	float	p0[2];
	float	p[2];
	int		iter;
	float	x_temp;

	pi[0] = -1;
	while (++(pi[0]) < dt->md->width)
	{
		pi[1] = -1;
		while (++(pi[1]) < dt->md->height)
		{
			setup_pi_p0_iter(dt, pi, p0, &iter);
			p[0] = 0.0;
			p[1] = 0.0;
			while (p[0] * p[0] + p[1] * p[1] < 4 && ++iter < dt->cf->max_iter)
			{
				x_temp = p[0] * p[0] - p[1] * p[1] + p0[0];
				p[1] = float_abs(2 * p[0] * p[1] + p0[1]);
				p[0] = float_abs(x_temp);
			}
			fractal_color(dt, pi[0], pi[1], iter);
		}
	}
}

void	tricorn(t_data *dt)
{
	int		pi[2];
	float	p0[2];
	float	p[2];
	int		iter;
	float	x_temp;

	pi[0] = -1;
	while (++(pi[0]) < dt->md->width)
	{
		pi[1] = -1;
		while (++(pi[1]) < dt->md->height)
		{
			setup_pi_p0_iter(dt, pi, p0, &iter);
			p[0] = 0.0;
			p[1] = 0.0;
			while (p[0] * p[0] + p[1] * p[1] < 4 && ++iter < dt->cf->max_iter)
			{
				x_temp = p[0] * p[0] - p[1] * p[1] + p0[0];
				p[1] = -2 * p[0] * p[1] + p0[1];
				p[0] = x_temp;
			}
			fractal_color(dt, pi[0], pi[1], iter);
		}
	}
}
