/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:02:48 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/18 18:39:35 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initj(t_data *data)
{
	data->zoom = 0.25f;
	data->img_x = 600;
	data->img_y = 600;
	data->himg_x = data->img_x / 2;
	data->himg_y = data->img_y / 2;
	data->mx = 0;
	data->my = 0;
	data->cr = 0.0;
	data->ci = 0.0;
	data->ox = 0.0;
	data->oy = 0.0;
	data->on = 1;
	data->v = 0.1;
	data->ic1 = 85 + 35;
	data->ic2 = 105 + 240;
	data->ic3 = 205 + 105;
	data->iterationmax = 35;
}

void	init_mlximg(t_data *data)
{
	if (!(data->img = mlx_new_image(data->mlx, data->img_x, data->img_y)))
		ft_putendl("error");
	data->pixel_img = mlx_get_data_addr(data->img, &(data->bpp),
			&(data->img_line), &(data->ed));
}

void	init_mlx(t_data *data)
{
	initj(data);
	if ((data->mlx = mlx_init()) == NULL)
		ft_putendl("Error");
	if ((data->win = mlx_new_window(data->mlx, data->img_x, data->img_y,
					"Fractol")) == NULL)
		ft_putendl("Error");
	init_mlximg(data);
}

void	choose_color(t_data *data, int x, int y)
{
	data->r2 = cos(data->i * data->v) * data->ic1;
	data->g2 = cos(data->i * data->v) * data->ic2;
	data->b2 = cos(data->i * data->v) * data->ic3;
	if (data->i == data->iterationmax)
	{
		data->r = 0;
		data->g = 0;
		data->b = 0;
	}
	else
	{
		data->r = data->r2;
		data->g = data->g2;
		data->b = data->b2;
	}
	put_pixel_to_img(x, y, data);
}

void	winhelp(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 700, 700, "SHORTCUT");
	mlx_string_put(mlx, win, 320, 10, 0xFF00FF, "SHORTCUT :");
	mlx_string_put(mlx, win, 20, 50, 0xFF0000,
			"w, s, a, d = deplacer la fractale");
	mlx_string_put(mlx, win, 20, 150, 0xFFFF00,
			"+ / - = ajouter / enlever des iterations ");
	mlx_string_put(mlx, win, 20, 250, 0xFF0000,
			"fleche de droite et de gauche = changer de fractale");
	mlx_string_put(mlx, win, 20, 350, 0xFFFF00,
			"1 / 2 / 3 / 4 = changer la couleur de la fractale");
	mlx_string_put(mlx, win, 20, 450, 0xFF0000,
			"clear = retourner au parametre par default de la fractale");
	mlx_string_put(mlx, win, 20, 550, 0xFFFF00,
			"delete / fn = figer la fractale / defiger la fractale");
	mlx_string_put(mlx, win, 20, 650, 0xFF0000,
			"> / < = modifier les reglages de profondeur de la couleur");
	mlx_loop(mlx);
}
