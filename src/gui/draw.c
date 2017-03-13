/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:05 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/13 17:07:29 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_pixel(t_env *e, t_color color, int x, int y)
{
	int			i;

	i = x * 4 + y * e->size;
	e->data[i] = (color.b);
	e->data[i + 1] = (color.g);
	e->data[i + 2] = (color.r);
}

void	apply_color_to_image(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			fill_pixel(e, e->color_array[y][x], x, y);
	}
}

void	update_image(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size), &(e->endian));
	draw(e);
}

void	draw(t_env *e)
{
	int			x;
	int			y;
	t_color		color;

	e->nb_cam_rays = WIN_W * WIN_H;
	e->nb_light_rays = 0;
	y = 0;
	while (y < WIN_H * e->scene->aa)
	{
		x = 0;
		while (x < WIN_W * e->scene->aa)
		{
			color = raytracer(e, x, y);
			color = apply_effects(e, color);
			e->color_array_aa[y][x] = color;
			x++;
		}
		y++;
	}
	super_sampling(e);
	apply_color_to_image(e);
	e->nb_rays = e->nb_cam_rays + e->nb_light_rays;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_gui_output(e);
	print_cli_output(e);
}
