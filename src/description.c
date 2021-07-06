/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:18:05 by seonchoi          #+#    #+#             */
/*   Updated: 2021/07/06 17:26:33 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	treat_description(char *file_name, t_info *info)
{
	int		fd;
	int		gnl_return;
	char	*line;
	int		ex;

	ex = file_name_check(file_name);
	if (!ex)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (!fd)
		return (-1);
	gnl_return = get_next_line(fd, &line);
	while (gnl_return == 1)
	{
		if (!parse_line(line, info))
			return (0);
		free(line);
		gnl_return = get_next_line(fd, &line);
	}
	if (!parse_line(line, info))
		return (0);
	free(line);
	close(fd);
	return (1);
}

int	parse_line(char *line, t_info *info)
{
	int		i;
	int		num;

	num = 0;
	i = 0;
	info->err = 0;
	while (line[i] != '\0')
	{
		if (is_space(line[i]))
		{
			i++;
			num++;
		}
		else if (is_type_identifier(line[i], line[i + 1], line, info))
			break ;
		else if (is_map_character(line[i]))
			i = i + save_map1(line, info) - num;
		else
			return (0);
	}
	if (info->err == -1)
		return (0);
	return (1);
}

int	is_type_identifier(char a, char b, char *line, t_info *info)
{
	int		i;
	t_color	color;

	i = 0;
	init_color(&color);
	if (((a == 'F' || a == 'C') && is_space(b)))
		i = config_color(a, line + 1, info, &color);
	else if (a == 'N' && b == 'O')
		i = config_path(0, line + 2, info);
	else if (a == 'S' && b == 'O')
		i = config_path(1, line + 2, info);
	else if (a == 'W' && b == 'E')
		i = config_path(2, line + 2, info);
	else if (a == 'E' && b == 'A')
		i = config_path(3, line + 2, info);
	else
		return (0);
	if (i == -1)
		return (0);
	return (1);
}
