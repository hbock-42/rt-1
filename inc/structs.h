/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:23:02 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/17 01:03:49 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct				s_fresnel
{
	float		cosi;
    float		etai;
	float		etat;
	float		tmp;
	float		sint;
	float		cost;
	float		rs;
	float		rp;
}							t_fresnel;

typedef struct				s_color
{
	float					r;
	float					g;
	float					b;
}							t_color;

typedef struct				s_vector
{
	double					x;
	double					y;
	double					z;
}							t_vector;

typedef struct				s_sphere
{
	t_vector				pos;
	float					r;
}							t_sphere;

typedef struct				s_plane
{
	t_vector				normal;
	float					offset;
	int						type;
	int						is_limited;
	t_vector				mins;
	t_vector				maxs;
}							t_plane;

typedef struct				s_cylinder
{
	t_vector				axis;
	t_vector				pos;
	t_vector				limit_max;
	t_vector				limit_min;
	float					r;
}							t_cylinder;

typedef struct				s_cone
{
	t_vector				axis;
	t_vector				limit_max;
	t_vector				limit_min;
	t_vector				apex;
	float					angle;
}							t_cone;

typedef struct				s_tore
{
	t_vector				pos;
	float					r;
	float					big_r;
}							t_tore;

typedef struct				s_boloid
{
	t_vector				pos;
	float					a;
	float					b;
	float					c;
}							t_boloid;

typedef struct				s_limit
{
	int						is_limited;
	t_vector				mins;
	t_vector				maxs;
}							t_limit;

typedef struct				s_mat
{
	int						type;
	float					diffuse;
	float					specular;
	float					reflexion;
	float					refraction;
	float					ior;
}							t_mat;

typedef struct				s_object
{
	int						type;
	void					*object;
	t_color					color;
	t_mat					material;
	int						id;
	struct s_object			*next;
}							t_object;

typedef struct				s_hitpoint
{
	t_vector				pos;
	t_vector				normal;
	t_color					color;
	t_object				*object;
}							t_hitpoint;

typedef struct				s_ray
{
	t_vector				o;
	t_vector				d;
	float					t;
	float					transmittance_ray;
	t_hitpoint				hitpoint;
	float					ior;
	float					past_ior;
	int						is_in;
}							t_ray;

typedef struct				s_ref
{
	t_color		color;
	t_color		reflect_color;
	t_color		refract_color;
	t_ray		reflect_ray;
	t_ray		refract_ray;
}							t_ref;

typedef struct				s_light
{
	int						type;
	float					intensity;
	t_vector				pos;
	t_vector				dir;
	t_color					color;
	struct s_light			*next;
}							t_light;

typedef struct				s_camera
{
	t_vector				pos;
	t_vector				dir;
	t_vector				dir_left;
	t_vector				dir_up;
	t_vector				rot;
	float					ratio;
	float					fov;
	float					focale;
}							t_camera;

typedef struct				s_scene
{
	t_color					background_color;
	t_camera				*camera;
	t_object				*objects;
	t_light					*lights;
	float					amb_intensity;
	t_color					amb_color;
	int						amb;
	int						dir;
	int						spot;
	int						diffuse;
	int						specular;
	t_object				*selected_object;
	int						nb_objects;
	int						nb_lights;
	int						mode;
	int						effect;
	int						aa;
	t_color					**color_array;
	t_color					**color_array_aa;
}							t_scene;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						size;
	int						endian;
	int						bpp;
	int						thread;
	int						scene_type;
	t_scene					*scene;
	double					nb_rays;
	double					nb_cam_rays;
	double					nb_light_rays;
	int						verbose;
	float					frame_time;
}							t_env;

#endif
