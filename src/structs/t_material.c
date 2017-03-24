/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_material.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:53:22 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 04:04:15 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mat			new_basic_material(void)
{
	t_mat		material;

	material.type = BASIC;
	material.diffuse = BASIC_DIFFUSE;
	material.specular = BASIC_SPECULAR;
	material.shininess = BASIC_SHININESS;
	material.reflexion = BASIC_REFLEXION;
	material.refraction = BASIC_REFRACTION;
	material.ior = BASIC_IOR;
	material.property = DIFFUSE;
	material.shadow = BASIC_SHADOW;
	return (material);
}

t_mat			new_bitref_material(void)
{
	t_mat		material;

	material.type = BIT_REF;
	material.diffuse = BITREF_DIFFUSE;
	material.specular = BITREF_SPECULAR;
	material.shininess = BITREF_SHININESS;
	material.reflexion = BITREF_REFLEXION;
	material.refraction = BITREF_REFRACTION;
	material.ior = BITREF_IOR;
	material.property = REFLECTIVE;
	material.shadow = BITREF_SHADOW;
	return (material);
}

t_mat			new_water_material(void)
{
	t_mat		material;

	material.type = WATER;
	material.diffuse = WATER_DIFFUSE;
	material.specular = WATER_SPECULAR;
	material.shininess = WATER_SHININESS;
	material.reflexion = WATER_REFLEXION;
	material.refraction = WATER_REFRACTION;
	material.ior = WATER_IOR;
	material.property = TRANSMITIVE;
	material.shadow = WATER_SHADOW;
	return (material);
}

t_mat			new_test_material(void)
{
	t_mat		material;

	material.type = TEST;
	material.diffuse = TEST_DIFFUSE;
	material.specular = TEST_SPECULAR;
	material.shininess = TEST_SHININESS;
	material.reflexion = TEST_REFLEXION;
	material.refraction = TEST_REFRACTION;
	material.ior = TEST_IOR;
	material.property = DIFFUSE;
	material.shadow = TEST_SHADOW;
	return (material);
}

t_mat			new_material(int type)
{
	t_mat		material;

	if (type == BASIC)
		material = new_basic_material();
	else if (type == PLASTIC)
		material = new_plastic_material();
	else if (type == GLASS)
		material = new_glass_material();
	else if (type == PERLIN)
		material = new_perlin_material();
	else if (type == BIT_REF)
		material = new_bitref_material();
	else if (type == WATER)
		material = new_water_material();
	else if (type == TEST)
		material = new_test_material();
	else // if (type == CHROME)
		material = new_chrome_material();
	return (material);
}
