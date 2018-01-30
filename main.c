/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:34:26 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 18:11:36 by nmanzini         ###   ########.fr       */
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

int		loop_hook(t_data *dt)
{
	ft_putstr("loop ");
	if (dt->cf->max_iter < 1024)
	{
		ft_putstr("max_iter = ");
		ft_putnbr(dt->cf->max_iter);
		ft_putchar(10);
		display(dt, dt->cf->fractal);
	}
	return(0);
}

int		main(int ac, char **av)
{
	static t_data	*dt;

	dt = init_data(dt);
	display(dt, dt->cf->fractal);

	mlx_key_hook(dt->md->win, call_keys, dt);
	mlx_mouse_hook(dt->md->win, mouse_hook, dt);
	// mlx_loop_hook(dt->md->win, loop_hook, dt);

	mlx_loop(dt->md->mlx);
	return (0);
}
