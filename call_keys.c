
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
	call_keys_zoom(keycode,dt);
	call_keys_general(keycode, dt);
	display(dt, Mandelbrot);
	return (0);
}
