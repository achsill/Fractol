/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:45:09 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/18 18:41:10 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# define WIDTH 1000
# define HEIGHT 500

typedef struct		s_data
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*pixel_img;
	int				bpp;
	int				img_line;
	int				ed;
	int				r;
	int				g;
	int				b;
	double			cx;
	double			cy;
	double			zx;
	double			zy;
	double			zx2;
	double			zy2;
	int				iterationmax;
	double			xmax;
	double			xmin;
	double			ymax;
	double			ymin;
	int				k;
	double			cr;
	double			ci;
	char			*d;
	double			ki;
	double			kr;
	double			ki2;
	double			kr2;
	double			img_x;
	double			img_y;
	double			zoom;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			nr;
	double			ni;
	double			jr;
	double			ji;
	double			ys;
	double			xs;
	double			tmp;
	int				choose;
	int				mouse_x;
	int				mouse_y;
	double			himg_x;
	double			himg_y;
	double			zoom_x;
	double			zoom_y;
	double			mx;
	double			my;
	double			ox;
	double			oy;
	int				mp;
	int				mm;
	int				on;
	double			tcr;
	double			tci;
	int				r2;
	int				g2;
	int				b2;
	int				i;
	double			v;
	int				ic1;
	int				ic2;
	int				ic3;
}					t_data;
void				mandelbrot(t_data *data, int ix, int iy);
void				put_pixel_to_img(int x, int y, t_data *data);
void				initj(t_data *data);
int					ft_shortcut(int keycode, t_data *data);
int					ft_mouse(int button, t_data *data);
void				choose_color(t_data *data, int x, int y);
void				julia(t_data *data, int ix, int iy);
void				tools(t_data *data, int y);
void				initjulia(t_data *data);
int					arg(t_data *data, int i);
void				choosef(t_data *data, int i);
void				drawff(t_data *data);
int					mouse_pos(int x, int y, t_data *data);
int					ft_mouseset(t_data *data);
int					ftl_expose_hook(t_data *data);
int					ft_mouseset(t_data *data);
void				init_all(t_data *data);
void				init_mlx(t_data *data);
void				init_mlximg(t_data *data);
int					mouse_zoom(int keycode, int x, int y, t_data *data);
void				color(t_data *data, int keycode);
void				winhelp(void);
#endif
