/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 07:17:32 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/17 10:13:52 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_tag_tofile(char *tag, int type, int tabs, int fd)
{
	while (tabs-- > 0)
		ft_putchar_fd('\t', fd);
	if (type == TAG_OPEN || type == TAG_OPEN_ENDL)
		ft_putstr_fd("<", fd);
	else
		ft_putstr_fd("</", fd);
	ft_putstr_fd(tag, fd);
	ft_putstr_fd(">", fd);
	if (type == TAG_CLOSE || type == TAG_OPEN_ENDL)
		ft_putstr_fd("\n", fd);
}

void			print_vector_tofile(t_vector v, char *name, int tabs, int fd)
{
	print_tag_tofile(name, TAG_OPEN, tabs, fd);
	dprintf(fd, "%.3f", v.x);
	ft_putstr_fd(", ", fd);
	dprintf(fd, "%.3f", v.y);
	ft_putstr_fd(", ", fd);
	dprintf(fd, "%.3f", v.z);
	print_tag_tofile(name, TAG_CLOSE, 0, fd);
}

void			print_color_tofile(t_color c, char *name, int tabs, int fd)
{
	print_tag_tofile(name, TAG_OPEN, tabs, fd);
	ft_putnbr_fd(c.r, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(c.g, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(c.b, fd);
	print_tag_tofile(name, TAG_CLOSE, 0, fd);
}