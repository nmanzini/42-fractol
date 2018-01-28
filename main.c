
#include "fractol.h"

t_mlx_data	*mlx_data_init_return(t_mlx_data *md)
{
	static t_mlx_data	actual_md;
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

t_data *init_data(t_data *dt)
{
	static t_data		actual_dt;
	static t_mlx_data	*md;

	dt = &actual_dt;
	dt->md = mlx_data_init_return(md);
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

	ft_putendl("Julia");
	Px = -1;
	while (++Px < dt->md->width)
	{
		Py = -1;
		while (++Py < dt->md->height)
		{
			x0 = -0.5;
			y0 = -0.5;
			x =  (Px * 2.0 / (float)dt->md->width) - 1;
			y =  (Py * 2.0 / (float)dt->md->height) - 1;
			iter = 0;
			max_iter = 1000;

			while (x * x + y * y < 4  &&  iter < max_iter) 
			{
				x_temp = x * x - y * y;
				y = 2 * x * y + y0;
				x = x_temp + x0;
				iter++;
			}
			fill_pixel(dt->md, Px, Py, iter * 256*256 + iter * 256 + iter);
		}
	}
	mlx_put_image_to_window(dt->md->mlx, dt->md->win, dt->md->ip->image, 0, 0);
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

	ft_putendl("Mandelbrot");
	Px = -1;
	while (++Px < dt->md->width)
	{
		Py = -1;
		while (++Py < dt->md->height)
		{
			x0 = (Px * 4.0 / (float)dt->md->width) - 2.5;
			y0 = (Py * 3.0 / (float)dt->md->height) - 1.5;
			x = 0.0;
			y = 0.0;
			iter = 0;
			max_iter = 1000;
			while (x * x + y * y < 4 && iter < max_iter)
			{
				x_temp = x * x - y * y + x0;
				y = 2 * x * y + y0;
				x = x_temp;
				iter++;
			}
			fill_pixel(dt->md, Px, Py, iter * 256*256 + iter * 256 + iter);
		}
	}
	mlx_put_image_to_window(dt->md->mlx, dt->md->win, dt->md->ip->image, 0, 0);
}

int			main(int ac, char **av)
{
	static t_data	*dt;

	dt = init_data(dt);

	Mandelbrot(dt);
	mlx_key_hook(dt->md->win, call_keys, dt->md);
	mlx_loop(dt->md->mlx);
	return (0);
}
