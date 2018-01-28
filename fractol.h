/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicola <nicola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:05:45 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/28 03:10:26 by nicola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MinilibX/elcapitan/mlx.h"
# include "libft/libft.h"
# include <math.h>

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
}					t_mlx_data;

typedef struct      s_data_struct
{
	t_mlx_data		*md;
	char			*name;
}					t_data;

# define WIDTH		800
# define HEIGHT		600


# define BLACK		0x00000000
# define WHITE		0x00FFFFFF

# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF


/*
** main.c
*/
t_mlx_data			*mlx_data_init_return(t_mlx_data *md);

/*
** call_keys.c
*/
int		call_keys(int keycode, t_mlx_data *md);
void	call_keys_general(int keycode, t_mlx_data *md);
/*
** call_keys_utils.c
*/
/*
** call_keys_color.c
*/
/*
** input.c
*/
/*
** mlx_utils.c
*/
void				fill_dot(t_mlx_data *md, int x, int y, int radius);
void				make_image(t_mlx_data *md);
void				img_square(t_mlx_data *md, unsigned int color);
void				fill_pixel(t_mlx_data *md, int x, int y,
								unsigned int color);

#endif
