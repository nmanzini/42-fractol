/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:34:10 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/31 12:34:36 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>

#include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"

typedef struct		s_image_struct
{
	int				*lst;
	void			*image;
}					t_img_prm;

typedef struct		s_str_struct
{
	int				x;
	int				y;
}					t_str;

typedef struct		s_mlx_struct
{
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	char			type;
	t_img_prm		*ip;
}					t_mlx;

typedef struct		s_cfg_struct
{
	int				x_mouse;
	int				y_mouse;
	float			x_zoom;
	float			y_zoom;
	float			x_move;
	float			y_move;
	float			x_center;
	float			y_center;
	float			x_julia;
	float			y_julia;
	char			mode;
	char			progressive;
	int				f_flag;
	int				max_iter;
	int				max_iter_original;

	int				c_flag;
	int				c_slices;
	int				c_s_size;
	unsigned int	c_inside;
	unsigned int	(*i_to_c[10])();
	void			(*fractal)();
}					t_cfg;

typedef struct      s_data_struct
{
	t_cfg			*cf;
	t_str			*st;
	t_mlx			*md;
	char			*name;
}					t_data;

# define WIDTH		1024
# define HEIGHT		1024

# define BLACK		0x00000000
# define WHITE		0x00FFFFFF

# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF

/*
** main.c
*/
float				float_abs(float f);
void				display(t_data *dt, void (*f)(t_data*));
int					read_input(t_data *dt, int ac, char **av);
int					motion_function(int x, int y,  t_data *dt);
/*
** data_init.c
*/
t_mlx				*mlx_data_init_return(t_mlx *md);
void				cfg_setup(t_cfg *cf);
t_cfg				*cfg_data_init(t_cfg *cf);
t_data				*init_data(t_data *dt);
/*
** fractals.c
*/
void				mandelbrot(t_data *dt);
void				julia(t_data *dt);
void				burning_ship(t_data *dt);
void				tricorn(t_data *dt);
/*
** call_keys_general.c
*/
int					call_keys(int keycode, t_data *dt);
void				call_keys_general(int keycode, t_data *dt);
/*
** call_keys.c
*/
void				call_keys_position(int keycode, t_data *dt);
void				call_keys_zoom(int keycode, t_data *dt);
void				call_keys_type(int keycode, t_data *dt);
void				call_keys_mode_reset(int keycode, t_data *dt);
void				call_keys_color(int keycode, t_data *dt);
/*
** mlx_utils.c
*/
void				fill_dot(t_mlx *md, int x, int y, int radius);
void				make_image(t_mlx *md);
void				img_square(t_mlx *md, unsigned int color);
void				fill_pixel(t_mlx *md, int x, int y,
								unsigned int color);
/*
** colors_utlis.c
*/
unsigned int	rgb(int red, int green, int blue);
void			fractal_color(t_data *dt, int x, int y, int iter);
/*
** colors_palette_1.c
*/
unsigned int		iter_to_color_0(t_data *dt,int iter);
unsigned int		iter_to_color_1(t_data *dt,int iter);
unsigned int		iter_to_color_2(t_data *dt,int iter);
unsigned int		iter_to_color_3(t_data *dt,int iter);
unsigned int		iter_to_color_4(t_data *dt,int iter);
/*
** colors_palette_2.c
*/
unsigned int		iter_to_color_5(t_data *dt, int iter);
unsigned int		iter_to_color_grey(t_data *dt, int iter);
unsigned int		iter_to_color_red(t_data *dt, int iter);
unsigned int		iter_to_color_green(t_data *dt, int iter);
unsigned int		iter_to_color_blue(t_data *dt, int iter);
/*
** mouse.c
*/
void 				zoom(t_data *dt,char drection);
int					mouse_hook(int button, int x, int y, t_data *dt);

#endif
