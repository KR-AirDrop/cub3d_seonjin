/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:18:08 by seonchoi          #+#    #+#             */
/*   Updated: 2021/07/06 15:37:13 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_color(t_color *color)
{
	color->i = 0;
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

int	config_color(char location, char *line, t_info *info, t_color *color)
{
	while (!(ft_isdigit(line[color->i])))
		color->i++;
	while (line[color->i] && ft_isdigit(line[color->i]))
	{
		color->r = color->r * 10 + (line[color->i] - '0');
		color->i++;
	}
	while (!(ft_isdigit(line[color->i])))
		color->i++;
	while (line[color->i] && ft_isdigit(line[color->i]))
	{
		color->g = color->g * 10 + (line[color->i] - '0');
		color->i++;
	}
	while (!(ft_isdigit(line[color->i])))
		color->i++;
	while (line[color->i] && ft_isdigit(line[color->i]))
	{
		color->b = color->b * 10 + (line[color->i] - '0');
		color->i++;
	}
	if (!put_rgb(location, info, color))
		return (-1);
	return (1);
}

int	config_path(int index, char *line, t_info *info)
{
	int		start;
	int		end;
	char	*path;

	start = 0;
	while (is_space(line[start]))
		start++;
	end = ft_strlen(line);
	path = ft_substr(line, start, end - start);
	if (!path || file_exists(path) == -1)
		return (-1);
	info->path[index] = path;
	return (1);
}

int	put_rgb(char location, t_info *info, t_color *color)
{
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (0);
	color->color = (color->r * 256 * 256) + (color->g * 256) + color->b;
	if (location == 'F')
		info->floor_color = color->color;
	else if (location == 'C')
		info->ceiling_color = color->color;
	return (1);
}
