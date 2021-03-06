/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_keys_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:02:37 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/31 18:04:15 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	call_keys_general(int keycode, t_data *dt)
{
	if (keycode == 53)
	{
		ft_putendl("ESC		Bye bye!\n");
		mlx_destroy_window(dt->md->mlx, dt->md->win);
		exit(0);
	}
	else if (keycode == 50)
	{
		ft_putendl("`		Bye bye and may 0 leaks be with you\n");
		mlx_destroy_window(dt->md->mlx, dt->md->win);
		while (1)
			;
	}
	else if (keycode == 35)
	{
		ft_putstr("P 		progressive switch ");
		if (dt->cf->progressive == 'y')
			dt->cf->progressive = 'n';
		else
			dt->cf->progressive = 'y';
		ft_putchar(dt->cf->progressive);
		ft_putchar('\n');
	}
}

int		call_keys(int keycode, t_data *dt)
{
	dt->cf->max_iter = dt->cf->max_iter_original;
	call_keys_position(keycode, dt);
	call_keys_zoom(keycode, dt);
	call_keys_type(keycode, dt);
	call_keys_general(keycode, dt);
	call_keys_mode_reset(keycode, dt);
	call_keys_color(keycode, dt);
	display(dt, dt->cf->fractal);
	return (0);
}
