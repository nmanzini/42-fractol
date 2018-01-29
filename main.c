/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:34:26 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/29 18:28:33 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float 	float_abs(float f)
{
	if (f < 0)
		return (-f);
	else
		return (f);
}

t_mlx	*mlx_data_init_return(t_mlx *md)
{
	static t_mlx	actual_md;
	static t_img_prm	actual_ip;

	md = &actual_md;
	md->ip = &actual_ip;
	md->width = WIDTH;
	md->height = HEIGHT;
	md->mlx = mlx_init();
	md->win = mlx_new_window(md->mlx, md->width, md->height, "fractol");
	make_image(md);
	return (md);
}

void	cfg_setup(t_cfg *cf)
{
	cf->x_zoom = 4;
	cf->y_zoom = cf->x_zoom / WIDTH * HEIGHT;
	cf->x_center = 0;
	cf->y_center = 0;
	cf->x_move = WIDTH / 2;
	cf->y_move = HEIGHT / 2;
	cf->mode = 'z';
	cf->x_Julia = 0.285;
	cf->y_Julia = 0.01;
	cf->max_iter = 500;

}

t_cfg	*cfg_data_init(t_cfg *cf)
{
	static t_cfg	actual_cfg;

	cf = &actual_cfg;
	cfg_setup(cf);
	cf->fractal = Mandelbrot;
	cf->flag = 0;
	return (cf);
}

t_data	*init_data(t_data *dt)
{
	static t_data		actual_dt;
	static t_mlx		*md;
	static t_cfg		*cf;

	dt = &actual_dt;
	dt->md = mlx_data_init_return(md);
	dt->cf = cfg_data_init(cf);
	return (dt);
}

void	fractal_color(t_data *dt, int x, int y, int iter)
{
	int				slices;
	float			max_local;
	int				i;
	int				multiplier;
	unsigned int	color;

	multiplier = 1;

	slices = dt->cf->max_iter / 20;
	max_local = dt->cf->max_iter / (float)slices;


	color = BLACK;

	i = 0;
	while (i < slices)
	{
		multiplier *= 256;
		if (iter > max_local * i)
		{
			color = iter - (max_local * i);
			color = color / max_local * multiplier ;
		}
		i++;
		if (slices % 3 == 0)
			multiplier = 1; 
	}
	fill_pixel(dt->md, x, y, color);
}

void	fractal_colora(t_data *dt, int x, int y, int iter)
{
	int				slices;
	int				max_local;
	unsigned int	multiplier;
	unsigned int	color;

	multiplier = 255 * 255;

	slices = dt->cf->max_iter / 20;
	max_local = dt->cf->max_iter / slices;		// 500 / 10 = 50
	// color = BLACK;

	// if (iter != dt->cf->max_iter)
	// {
		color = (unsigned int)(((iter % max_local) / max_local) * multiplier) ;
	// }
	fill_pixel(dt->md, x, y, color);
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

void	display(t_data *dt, void (*f)(t_data*))
{
	f(dt);
	mlx_put_image_to_window(dt->md->mlx, dt->md->win, dt->md->ip->image, 0, 0);
}

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

int			main(int ac, char **av)
{
	static t_data	*dt;

	dt = init_data(dt);

	display(dt, dt->cf->fractal);
	mlx_key_hook(dt->md->win, call_keys, dt);
    mlx_mouse_hook(dt->md->win, mouse_hook, dt);
	mlx_loop(dt->md->mlx);
	return (0);
}
