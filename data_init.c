/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:07:52 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 20:29:41 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*mlx_data_init_return(t_mlx *md)
{
	static t_mlx		actual_md;
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
	cf->max_iter_original = 128;
	cf->max_iter = 128;
	cf->c_slices = cf->max_iter / 8;
	cf->c_s_size = cf->max_iter / (float)cf->c_slices;
	cf->c_inside = WHITE;
}

t_cfg	*cfg_data_init(t_cfg *cf)
{
	static t_cfg	actual_cfg;

	cf = &actual_cfg;
	cfg_setup(cf);
	cf->fractal = mandelbrot;
	cf->x_julia = 0.285;
	cf->y_julia = 0.01;
	cf->f_flag = 0;
	cf->c_flag = 0;
	cf->i_to_c[0] = iter_to_color_0;
	cf->i_to_c[1] = iter_to_color_1;
	cf->i_to_c[2] = iter_to_color_2;
	cf->i_to_c[3] = iter_to_color_3;
	cf->i_to_c[4] = iter_to_color_4;
	cf->i_to_c[5] = iter_to_color_5;
	cf->i_to_c[6] = iter_to_color_grey;
	cf->i_to_c[7] = iter_to_color_red;
	cf->i_to_c[8] = iter_to_color_green;
	cf->i_to_c[9] = iter_to_color_blue;
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
