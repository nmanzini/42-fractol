/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:34:26 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 20:29:00 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	float_abs(float f)
{
	if (f < 0)
		return (-f);
	else
		return (f);
}

void	display(t_data *dt, void (*f)(t_data*))
{
	f(dt);
	mlx_put_image_to_window(dt->md->mlx, dt->md->win, dt->md->ip->image, 0, 0);
}

int		read_input(t_data *dt, int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("usage: ./fractol fractal_name");
		ft_putstr("possible fractal_name:");
		ft_putendl(" mandelbrot, julia, burning_ship, tricorn");
		return (1);
	}
	else
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			dt->cf->fractal = mandelbrot;
		else if (!ft_strcmp(av[1], "julia"))
			dt->cf->fractal = julia;
		else if (!ft_strcmp(av[1], "burning_ship"))
			dt->cf->fractal = burning_ship;
		else if (!ft_strcmp(av[1], "tricorn"))
			dt->cf->fractal = tricorn;
		else
		{
			ft_putendl("Worng fractal_name, try with:");
			ft_putendl(" mandelbrot, julia, burning_ship, tricorn");
			return (1);
		}
		return (0);
	}
}

int		motion_function(int x, int y, t_data *dt)
{
	dt->cf->x_julia = (x - dt->md->width / 2.0) / dt->md->width * 2.0;
	dt->cf->y_julia = (y - dt->md->height / 2.0) / dt->md->height * 2.0;
	display(dt, dt->cf->fractal);
	return(0);
}

int		main(int ac, char **av)
{
	static t_data	*dt;

	dt = init_data(dt);
	if (read_input(dt, ac, av))
		return (1);
	display(dt, dt->cf->fractal);
	mlx_key_hook(dt->md->win, call_keys, dt);
	mlx_mouse_hook(dt->md->win, mouse_hook, dt);
	mlx_hook(dt->md->win,MotionNotify,PointerMotionMask,motion_function,dt);
	mlx_loop(dt->md->mlx);
	return (0);
}
