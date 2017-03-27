/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <mmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 05:53:22 by mmorice           #+#    #+#             */
/*   Updated: 2017/03/27 20:02:52 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			free_array(char **array)
{
	int			i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int				create_object(t_env *e, char **tab)
{
	t_color		color;
	int			type;
	t_mat		material;
	t_vector	limits[2];

	limits[0] = get_vector(tab, "min", "limits");
	limits[1] = get_vector(tab, "max", "limits");
	type = get_object(e, tab, "type", "object");
	color = new_color(get_color(e, tab, "color", "object"));
	material = new_material(get_material(e, tab, "material", "object"));
	type == SPHERE ? add_object(e->scene, new_object(type,
		new_sphere(get_vector(tab, "pos", "sphere"),
		get_nbr(tab, "r", "sphere"), get_vector(tab, "axis", "sphere"), limits),
		color, material)) : NULL;
	type == PLANE ? add_object(e->scene, new_object(type,
		new_plane(get_vector(tab, "normal", "plane"),
		get_nbr(tab, "offset", "plane"),
		get_pstyle(e, tab, "style", "plane"), limits), color, material)) : NULL;
	type == CYLINDER ? add_object(e->scene, new_object(type,
		new_cylinder(get_vector(tab, "axis", "cylinder"),
		get_vector(tab, "pos", "cylinder"),
		get_nbr(tab, "r", "cylinder"), limits), color, material)) : NULL;
	type == CONE ? add_object(e->scene, new_object(type,
		new_cone(get_vector(tab, "axis", "cone"),
		get_vector(tab, "apex", "cone"),
		get_nbr(tab, "angle", "cone"), limits), color, material)) : NULL;
	return (0);
}

int				create_light(t_env *e, char **tab)
{
	int			color;
	int			type;
	int			intensity;

	type = get_light(e, tab, "type", "light");
	color = get_color(e, tab, "color", "light");
	intensity = 1;
	add_light(e->scene, new_light(type, intensity,
	get_vector(tab, "vector", "light"), new_color(color)));
	return (0);
}

int				get_object(t_env *e, char **array, char *tag, char *tagg)
{
	char		*str;
	int			start;
	int			end;
	int			i;

	i = 0;
	start = tag_present(array, tagg, "open") + 1;
	end = tag_present(array, tagg, "close") - 1;
	str = between_tags(&array[start], tag, end);
	while (ft_strcmp(e->macros.objects[i].define, "end"))
	{
		if (!(ft_strcmp(str, e->macros.objects[i].define)))
		{
			free(str);
			return (e->macros.objects[i].value);
		}
		i++;
	}
	print_parser_error(str, NOT_DEFINE_ERROR, 0);
	return (0);
}
