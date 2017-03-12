/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 03:18:42 by valentin          #+#    #+#             */
/*   Updated: 2017/03/11 10:36:51 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		get_normal(t_ray *ray)
{
	t_vector	normal;

	if (ray->hitpoint.object->type == SPHERE)
		normal = normalize(vector_sub(ray->hitpoint.pos,
			((t_sphere *)ray->hitpoint.object->object)->pos));
	else if (ray->hitpoint.object->type == PLANE)
		normal = get_normal_at_plane(ray, ray->hitpoint.object->object);
	else if (ray->hitpoint.object->type == CYLINDER)
		normal = get_normal_at_cylinder(ray, ray->hitpoint.object->object);
	else
		normal = get_normal_at_cone(ray, ray->hitpoint.object->object);
	if (ray->hitpoint.object->material.type == PERLIN)
		normal = vector_rot_y(normal, perlin(ray->hitpoint.pos, 75) * 30);
	return (normalize(normal));
}

t_vector		get_normal_at_plane(t_ray *ray, t_plane *plane)
{
	t_vector	normal;
	float		wave_height;
	float		wave_width;

	wave_height = 20;
	wave_width = 2;
	if (plane->type == WAVE || plane->type == CHECK_WAVE)
		normal = vector_rot_z(plane->normal,
			sin(ray->hitpoint.pos.x * wave_width) * wave_height);
	else
		normal = (plane->normal);
	return (normal);
}


t_vector		get_normal_at_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_vector	normal;
	t_vector	tmp;
	t_vector	project;
	float		dot;

	tmp = vector_sub(ray->hitpoint.pos, cylinder->pos);
	dot = dot_product(tmp, cylinder->axis);
	project = vector_scalar(dot, cylinder->axis);
	normal = vector_sub(tmp, project);
	return (normal);
}

t_vector		get_normal_at_cone(t_ray *ray, t_cone *cone)
{
	t_vector	normal;
	t_vector	tmp;
	t_vector	project;
	float		dot;

	tmp = vector_sub(ray->hitpoint.pos, cone->apex);
	dot = dot_product(tmp, cone->axis);
	project = vector_scalar(dot, cone->axis);
	normal = vector_sub(tmp, project);
	return (normal);
}

t_vector		get_normal_at_tore(t_ray *ray, t_tore *tore)
{
  	t_vector	hit;
	t_vector	normal;

	hit = ray->hitpoint.pos;
	normal.x = 4 * hit.x *
	  (pow(hit.x, 2) + pow(hit.y, 2) + pow(hit.z, 2) + pow(tore->R, 2) - pow(tore->r, 2)) -
	  (8 * pow(tore->R, 2) * hit.x);
	normal.y = 4 * hit.y *
	  (pow(hit.x, 2) + pow(hit.y, 2) + pow(hit.z, 2) + pow(tore->R, 2) - pow(tore->r, 2));
	normal.z = 4 * hit.z *
	  (pow(hit.x, 2) + pow(hit.y, 2) + pow(hit.z, 2) + pow(tore->R, 2) - pow(tore->r, 2)) -
	  (8 * pow(tore->R, 2) * hit.z);
	return (normal);
}
