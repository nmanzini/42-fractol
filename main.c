/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicola <nicola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:13:29 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/28 03:11:56 by nicola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	md->win = mlx_new_window(md->mlx, md->width, md->height, "fdf nmanzini");
	make_image(md);
	return (md);
}

int 	Mandelbrot(t_mlx_data	*md)
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
	while (++Px < md->width)
	{
		Py = -1;
		while (++Py < md->height)
		{
			x0 = (Px * 4 / (float)md->width) - 2.5;
			y0 = (Py * 3 / (float)md->height) - 1.5;
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

			if (iter < 100)
				fill_pixel(md, Px, Py, WHITE);
			else
				fill_pixel(md, Px, Py, BLACK);
		}
	}
	mlx_put_image_to_window(md->mlx, md->win, md->ip->image, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	static	t_mlx_data	*md;

	md = mlx_data_init_return(md);

	Mandelbrot(md);
	mlx_key_hook(md->win, call_keys, md);
	mlx_loop(md->mlx);
	return (0);
}
