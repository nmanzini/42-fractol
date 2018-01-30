/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:38:43 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 18:29:50 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	call_keys_position(int keycode, t_data *dt)
{
	if (keycode == 123)
	{
		ft_putendl("left	move left");
		dt->cf->x_center -= dt->cf->x_move;
	}
	else if (keycode == 124)
	{
		ft_putendl("right	move right");
		dt->cf->x_center += dt->cf->x_move;
	}
	else if (keycode == 126)
	{
		ft_putendl("up		move up");
		dt->cf->y_center -= dt->cf->y_move;
	}
	else if (keycode == 125)
	{
		ft_putendl("down	move down");
		dt->cf->y_center += dt->cf->y_move;
	}
}

void	call_keys_zoom(int keycode, t_data *dt)
{
	if (keycode == 27)
	{
		ft_putendl("-		un-zoom");
		zoom(dt, 'z');
	}
	else if (keycode == 24)
	{
		ft_putendl("=		zoom");
		zoom(dt, 'u');
	}
}

void	call_keys_type(int keycode, t_data *dt)
{
	if (keycode == 3)
	{
		ft_putendl("F		changing fractal");
		if (dt->cf->f_flag == 0)
			dt->cf->fractal = julia;
		else if (dt->cf->f_flag == 1)
			dt->cf->fractal = burning_ship;
		else if (dt->cf->f_flag == 2)
			dt->cf->fractal = tricorn;
		else if (dt->cf->f_flag == 3)
		{
			dt->cf->fractal = mandelbrot;
			dt->cf->f_flag = -1;
		}
		dt->cf->f_flag++;
		dt->cf->mode = 'z';
		cfg_setup(dt->cf);
	}
}

void	call_keys_mode_reset(int keycode, t_data *dt)
{
	if (keycode == 46)
	{
		ft_putstr("M		");
		if (dt->cf->mode == 'z')
		{
			ft_putendl("switch to mouse-parameter mode");
			dt->cf->mode = 'p';
		}
		else if (dt->cf->mode == 'p')
		{
			ft_putendl("switch to mouse-zoom mode");
			dt->cf->mode = 'z';
		}
	}
	if (keycode == 15)
	{
		ft_putendl("R		Reset config");
		cfg_setup(dt->cf);
	}
}

void	call_keys_color(int keycode, t_data *dt)
{
	if (keycode == 8)
	{
		ft_putstr("C		changing color to set ");
		if (dt->cf->c_flag == 9)
			dt->cf->c_flag = 0;
		else
			dt->cf->c_flag += 1;
		ft_putnbr(dt->cf->c_flag);
		ft_putchar(10);
	}
}
