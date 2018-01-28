/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicola <nicola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:11:28 by nmanzini          #+#    #+#             */
/*   Updated: 2018/01/28 03:08:31 by nicola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	call_keys_general(int keycode, t_mlx_data *md)
{
	if (keycode == 53)
	{
		ft_putendl("ESC      Bye bye!");
		mlx_destroy_window(md->mlx, md->win);
		exit(0);
	}
	else if (keycode == 50)
	{
		ft_putendl("ESC      Bye bye!");
		mlx_destroy_window(md->mlx, md->win);
		while (1)
			;
	}
}

int		call_keys(int keycode, t_mlx_data *md)
{
	call_keys_general(keycode, md);
	return (0);
}
