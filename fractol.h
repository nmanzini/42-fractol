/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:34:10 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/29 17:42:29 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>

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
	float			x_zoom;
	float			y_zoom;
	float			x_move;
	float			y_move;
	float			x_center;
	float			y_center;
	float			x_Julia;
	float			y_Julia;
	char			mode;
	int				flag;
	int				max_iter;
	void			(*fractal)();
}					t_cfg;

typedef struct      s_data_struct
{
	t_cfg			*cf;
	t_str			*st;
	t_mlx			*md;
	char			*name;
}					t_data;

# define WIDTH		1600
# define HEIGHT		800

# define BLACK		0x00000000
# define WHITE		0x00FFFFFF

# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF


/*
** main.c
*/

void	cfg_setup(t_cfg *cf);
void	Julia(t_data *dt);
void 	Tricorn(t_data *dt);
void 	Mandelbrot(t_data *dt);
void 	Burning_ship(t_data *dt);
void	display(t_data *dt, void (*f)(t_data*));
/*
** call_keys.c
*/
int		call_keys(int keycode, t_data *dt);
void	call_keys_general(int keycode, t_data *dt);
/*
** mlx_utils.c
*/
void				fill_dot(t_mlx *md, int x, int y, int radius);
void				make_image(t_mlx *md);
void				img_square(t_mlx *md, unsigned int color);
void				fill_pixel(t_mlx *md, int x, int y,
								unsigned int color);

#endif
