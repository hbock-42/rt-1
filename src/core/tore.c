/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:11 by valentin          #+#    #+#             */
/*   Updated: 2017/01/30 23:02:58 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Ray to hit tore intersection is a 4th degree equation.
** eq4[5] is the a, b, c, d, e parameters of that equation.
*/
float			hit_tore(t_tore *tore, t_ray *ray)
{
  	float		eq4[5];
	float		t;
	t_vector	dist;

	eq4[0] = pow(pow(ray->d.x, 2) + pow(ray->d.y, 2) + pow(ray->d.z, 2), 2);
	eq4[1] = 4 * (pow(ray->d.x, 2) + pow(ray->d.y, 2) + pow(ray->d.z, 2)) *
	  ((ray->d.x * ray->o.x) + (ray->d.y * ray->o.y) + (ray->d.z * ray->o.z));
	eq4[2] = 2 * (pow(ray->d.x, 2) + pow(ray->d.y, 2) + pow(ray->d.z, 2)) *
	  (pow(ray->o.x, 2) + pow(ray->o.y, 2) + pow(ray->o.z, 2) + pow(tore->R, 2) - pow(tore->r, 2)) +
	  pow(((ray->d.x * ray->o.x) + (ray->d.y * ray->o.y) + (ray->d.z * ray->o.z)), 2) -
	  4 * pow(tore->R, 2) * (pow(ray->d.x, 2) + pow(ray->d.z, 2));
	eq4[3] = 4 * ((ray->d.x * ray->o.x) + (ray->d.y * ray->o.y) + (ray->d.z * ray->o.z)) *
	  (pow(ray->o.x, 2) + pow(ray->o.y, 2) + pow(ray->o.z, 2) + pow(tore->R, 2) - pow(tore->r, 2)) -
	  8 * pow(tore->R, 2) * ((ray->d.x * ray->o.x) + (ray->d.z * ray->o.z));
	eq4[4] = (pow(ray->o.x, 2) + pow(ray->o.y, 2) + pow(ray->o.z, 2) + pow(tore->R, 2) - pow(tore->r, 2)) -
	  4 * pow(tore->R, 2) * (pow(ray->d.x, 2) + pow(ray->d.z, 2));
	dist = vector_sub(ray->o, tore->pos);
	t = solve_deg4(eq4);
	return (t);
}