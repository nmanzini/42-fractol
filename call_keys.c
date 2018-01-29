/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:38:43 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/29 16:01:05 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	call_keys_position(int keycode, t_data *dt)
{
	if (keycode == 123) 				// left
	{
		ft_putendl("left	");
		dt->cf->x_center -= dt->cf->x_move;
	}
	else if (keycode == 124)			// right
	{
		ft_putendl("right	");
		dt->cf->x_center += dt->cf->x_move;
	}	
	else if (keycode == 126)			// up
	{
		ft_putendl("up		");
		dt->cf->y_center -= dt->cf->y_move;
	}
	else if (keycode == 125)			// down
	{
		ft_putendl("down	");
		dt->cf->y_center += dt->cf->y_move;
	}
}

void	call_keys_zoom(int keycode, t_data *dt)
{
	if (keycode == 27) 				// -
	{
		ft_putendl("-		");
		dt->cf->x_zoom *= 1.33;
		dt->cf->y_zoom *= 1.33;
		dt->cf->x_move *= 1.33;
		dt->cf->y_move *= 1.33;
	}
	else if (keycode == 24)			// +
	{
		ft_putendl("=		");
		dt->cf->x_zoom *= 0.66;
		dt->cf->y_zoom *= 0.66;
		dt->cf->x_move *= 0.66;
		dt->cf->y_move *= 0.66;
	}	
}

void	call_keys_type(int keycode, t_data *dt)
{
	if (keycode == 3) 				// F
	{
		ft_putendl("F		");
		if (dt->cf->flag == 0)
		{
			ft_putendl("Julia");
			dt->cf->fractal = Julia;
			dt->cf->flag++;
		}
		else if (dt->cf->flag == 1)
		{
			ft_putendl("Tricorn");
			dt->cf->fractal = Tricorn;
			dt->cf->flag++;
		}
		else if (dt->cf->flag == 2)
		{
			ft_putendl("Burning_ship");
			dt->cf->fractal = Burning_ship;
			dt->cf->flag++;
		}
		else if (dt->cf->flag == 3)
		{
			ft_putendl("Mandelbrot");
			dt->cf->fractal = Mandelbrot;
			dt->cf->fractal = 0;
		}
	}
}

void	call_keys_reset(int keycode, t_data *dt)
{
	if (keycode == 15) 				// R
	{
		ft_putendl("R		");
		cfg_setup(dt->cf);
	}
}

void	call_keys_mode(int keycode, t_data *dt)
{
	if (keycode == 46) 				// M
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
}

void	call_keys_general(int keycode, t_data *dt)
{
	if (keycode == 53)
	{
		ft_putendl("ESC      Bye bye!");
		mlx_destroy_window(dt->md->mlx, dt->md->win);
		exit(0);
	}
	else if (keycode == 50)
	{
		ft_putendl("ESC      Bye bye!");
		mlx_destroy_window(dt->md->mlx, dt->md->win);
		while (1)
			;
	}
}

int		call_keys(int keycode, t_data *dt)
{
	call_keys_position(keycode, dt);
	call_keys_zoom(keycode, dt);
	call_keys_type(keycode, dt);
	call_keys_general(keycode, dt);
	call_keys_reset(keycode, dt);
	call_keys_mode(keycode, dt);
	display(dt, dt->cf->fractal);
	return (0);
}
