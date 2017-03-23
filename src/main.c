/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:13 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/22 04:49:06 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
{
	t_env	e;

	e.scene = NULL;
	load_scene(SCENE_1, &e);
	if (ac > 1)
		parse_arguments(ac, av, &e);
	start_mlx(&e);
	return (0);
}
