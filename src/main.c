/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:42:11 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/19 14:27:06 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(int x, int y, t_data *data)
{
	int i;

	if (x <= 0 || x >= data->img_x || y <= 0 || y >= data->img_y)
		return ;
	i = (x * data->bpp / 8) + (y * data->img_line);
	data->pixel_img[i] = data->r;
	data->pixel_img[i + 1] = data->g;
	data->pixel_img[i + 2] = data->b;
}

int		choose(t_data *data, int ac, char **av)
{
	(void)ac;
	if (ac < 2 || ac > 2)
	{
		ft_putendl("Please choose a Fractal :");
		ft_putendl("Mandelbrot, Julia or Burningship.");
		return (1);
	}
	else if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
			data->choose = 1;
		else if (ft_strcmp(av[1], "Julia") == 0)
			data->choose = 2;
		else if (ft_strcmp(av[1], "Burningship") == 0)
			data->choose = 3;
		else
		{
			ft_putendl("Error");
			return (1);
		}
	}
	return (0);
}

int		ftl_expose_hook(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	init_mlximg(data);
	drawff(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

int		main(int ac, char **av)
{
	t_data data;

	if (choose(&data, ac, av) == 1)
		return (0);
	else
		init_mlx(&data);
	mlx_mouse_hook(data.win, mouse_zoom, &data);
	mlx_hook(data.win, 6, (1L << 6), mouse_pos, &data);
	mlx_expose_hook(data.win, ftl_expose_hook, &data);
	mlx_loop_hook(data.mlx, ft_mouseset, &data);
	mlx_hook(data.win, 2, 1, ft_shortcut, &data);
	mlx_loop(data.mlx);
	return (0);
}
