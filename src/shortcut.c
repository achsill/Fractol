/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:32:37 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/19 14:27:24 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_shortcut2(int keycode, t_data *data)
{
	if (keycode == 0)
		data->ox += 0.1;
	if (keycode == 2)
		data->ox -= 0.1;
	if (keycode == 13)
		data->oy += 0.1;
	if (keycode == 1)
		data->oy -= 0.1;
	if (keycode == 71)
		initj(data);
	if (keycode == 4)
		winhelp();
}

int		ft_shortcut(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69)
		data->iterationmax += 5;
	if (keycode == 78 && data->iterationmax > 5)
		data->iterationmax -= 5;
	if (keycode == 279)
		data->on = 1;
	if (keycode == 117)
		data->on = 0;
	color(data, keycode);
	if (keycode == 47)
		data->v += 0.1;
	if (keycode == 43 && data->v > 0.1)
		data->v -= 0.1;
	if (keycode == 124 && data->choose < 3)
		data->choose++;
	if (keycode == 123 && data->choose > 1)
		data->choose--;
	ft_shortcut2(keycode, data);
	return (0);
}

int		mouse_zoom(int keycode, int x, int y, t_data *data)
{
	data->mouse_x = x;
	data->mouse_y = y;
	if (keycode == 4)
	{
		data->zoom *= 1.10;
		data->mp = 1;
	}
	else if (keycode == 5)
	{
		data->zoom *= 0.90;
		data->mm = 1;
	}
	else
	{
		data->mp = 0;
		data->mm = 0;
	}
	return (0);
}

int		mouse_pos(int x, int y, t_data *data)
{
	data->mouse_x = x;
	data->mouse_y = y;
	return (1);
}

int		ft_mouseset(t_data *data)
{
	if (data->mp == 1 || data->mm == 1)
	{
		data->ox += (data->mouse_x - data->himg_x) / (data->himg_x) /
			data->zoom / 10;
		data->oy += (data->mouse_y - data->himg_y) / (data->himg_y) /
			data->zoom / 10;
		data->mp = 0;
		data->mm = 0;
	}
	if (data->choose == 2 && data->on == 1)
	{
		data->cr = (data->mouse_x - data->img_x / 2) / 300;
		data->ci = (data->mouse_y - data->img_y / 2) / 300;
	}
	ftl_expose_hook(data);
	return (1);
}
