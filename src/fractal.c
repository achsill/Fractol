/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 19:38:40 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/18 17:17:17 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_data *data, int ix, int iy)
{
	double tmp;

	data->i = 0;
	data->kr = (ix - data->himg_x) / data->zoom_x + data->ox;
	data->ki = (iy - data->himg_y) / data->zoom_y + data->oy;
	while (data->i < data->iterationmax && (data->kr * data->kr + data->ki
				* data->ki) < 4)
	{
		tmp = data->kr;
		data->kr = data->kr * data->kr - data->ki * data->ki + data->cr;
		data->ki = 2 * data->ki * tmp + data->ci;
		data->i++;
	}
	choose_color(data, ix, iy);
}

void	mandelbrot(t_data *data, int ix, int iy)
{
	double tmp;

	data->cr = (ix - data->himg_x) / data->zoom_x + data->ox + data->mx;
	data->ci = (iy - data->himg_y) / data->zoom_y + data->oy + data->my;
	data->kr = 0;
	data->ki = 0;
	data->i = 0;
	while (data->i < data->iterationmax && (data->kr * data->kr + data->ki
				* data->ki) < 4)
	{
		tmp = data->kr;
		data->kr = data->kr * data->kr - data->ki * data->ki + data->cr;
		data->ki = 2 * data->ki * tmp + data->ci;
		++data->i;
	}
	choose_color(data, ix, iy);
}

void	burningship(t_data *data, int ix, int iy)
{
	data->i = 0;
	data->kr = 0;
	data->ki = 0;
	data->ki2 = 0;
	data->kr2 = 0;
	data->cr = (ix - data->himg_x) / data->zoom_x + data->ox;
	data->ci = (iy - data->himg_y) / data->zoom_y + data->oy;
	while (data->i < data->iterationmax && (data->kr * data->kr + data->ki *
				data->ki) < 4)
	{
		data->ki = 2.0 * fabs(data->kr * data->ki) + data->ci;
		data->kr = data->kr2 - data->ki2 - data->cr;
		data->kr2 = data->kr * data->kr;
		data->ki2 = data->ki * data->ki;
		++data->i;
	}
	choose_color(data, ix, iy);
}

void	drawff(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	data->zoom_x = data->zoom * data->img_x;
	data->zoom_y = data->zoom * data->img_y;
	while (y < data->img_y)
	{
		x = 0;
		while (x < data->img_x)
		{
			if (data->choose == 2)
				julia(data, x, y);
			if (data->choose == 1)
				mandelbrot(data, x, y);
			if (data->choose == 3)
				burningship(data, x, y);
			x++;
		}
		y++;
	}
}
