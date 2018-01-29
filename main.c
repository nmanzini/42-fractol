
#include "fractol.h"

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
}

t_cfg	*cfg_data_init(t_cfg *cf)
{
	static t_cfg	actual_cfg;

	cf = &actual_cfg;
	cfg_setup(cf);
	cf->fractal = Mandelbrot;
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

void	Julia(t_data *dt)
{
	int Px;
	int Py;
	float x0;
	float y0;
	int iter;
	int max_iter;
	float x;
	float x_temp;
	float y;

	Px = -1;
	while (++Px < dt->md->width)
	{
		Py = -1;
		while (++Py < dt->md->height)
		{
			x0 = -0.5;
			y0 = -0.5;
			x = Px - dt->md->width / 2.0;
			y = Py - dt->md->height / 2.0;
			x = x / (float)dt->md->width * dt->cf->x_zoom; 
			y = y / (float)dt->md->height * dt->cf->y_zoom;
			x = x + dt->cf->x_center / (float)dt->md->width;
			y = y + dt->cf->y_center / (float)dt->md->height;
			iter = 0;
			max_iter = 255;

			while (x * x + y * y < 4  &&  iter < max_iter) 
			{
				x_temp = x * x - y * y;
				y = 2 * x * y + y0;
				x = x_temp + x0;
				iter++;
			}
			fill_pixel(dt->md, Px, Py, iter );
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
	int max_iter;
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
			max_iter = 255;
			while (x * x + y * y < 4 && iter < max_iter)
			{
				x_temp = x * x - y * y + x0;
				y = 2 * x * y + y0;
				x = x_temp;
				iter++;
			}
			fill_pixel(dt->md, Px, Py, iter );
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
		dt->cf->x_center += (x - dt->md->width / 2) * dt->cf->x_zoom;
		dt->cf->y_center += (y - dt->md->height / 2) * dt->cf->y_zoom;
		dt->cf->x_zoom *= 0.66;
		dt->cf->y_zoom *= 0.66;
		dt->cf->x_move *= 0.66;
		dt->cf->y_move *= 0.66;
	}
	else if  (dt->cf->mode == 'p')
	{

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
