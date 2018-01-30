/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_palette_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:53:14 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/30 15:23:45 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int iter_to_color_5(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(value/3 + 100 , 255 - value/3 , value / 2) ;
	}
	return (color);
}

unsigned int iter_to_color_GREY(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(value/2 + 100 , value/2 + 100 , value/2 + 100) ;
	}
	return (color);
}

unsigned int iter_to_color_RED(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(value/2 + 100 , 0 ,0) ;
	}
	return (color);
}

unsigned int iter_to_color_GREEN(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(0, value/2 + 100 ,0) ;
	}
	return (color);
}

unsigned int iter_to_color_BLUE(t_data *dt,int iter)
{
	int				value;
	unsigned int	color;

	if (iter == dt->cf->max_iter)
		color = dt->cf->c_inside;
	else
	{
		value = (iter % dt->cf->c_s_size ) / (float) dt->cf->c_s_size  * 255;
		color = rgb(0, 0, value/2 + 100) ;
	}
	return (color);
}