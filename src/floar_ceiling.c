/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floar_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:18:11 by seonchoi          #+#    #+#             */
/*   Updated: 2021/07/01 21:18:34 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floar_casting(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y < height / 2 + 1)
				info->buf[y][x] = info->ceiling_color;
			if (y > height / 2 + 1)
				info->buf[y][x] = info->floor_color;
			x++;
		}
		y++;
	}
}
