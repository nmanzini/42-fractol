/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_palette_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:08:49 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 15:33:03 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int iter_to_color_0(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(value/2 + 100 , 255 - value/2 , value/2 + 122) ;
	}
	return (color);
}

unsigned int iter_to_color_1(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(255 - value/2 , 150 , value/2 + 122) ;
	}
	return (color);
}

unsigned int iter_to_color_2(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(200 , 255 - value/2 , value/3 - 255) ;
	}
	return (color);
}

unsigned int iter_to_color_3(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(255 - value / 2 , 0 , 122 + value / 2) ;
	}
	return (color);
}

unsigned int iter_to_color_4(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(value/2 + 100 , 255 - value/2 , 255) ;
	}
	return (color);
}
