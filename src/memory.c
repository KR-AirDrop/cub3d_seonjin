/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:15:02 by seonchoi          #+#    #+#             */
/*   Updated: 2021/07/01 20:57:50 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	memory_plus(t_info *info)
{
	int	i[2];

	i[0] = 0;
	info->texture = (int **)malloc(sizeof(int *) * 11);
	if (!info->texture)
		return (-1);
	while (i[0] < 11)
	{
		info->texture[i[0]] = (int *)malloc(sizeof(int) * (Tex_H * Tex_W));
		if (!info->texture[i[0]])
			return (-1);
		i[0]++;
	}
	i[0] = 0;
	while (i[0] < 11)
	{
		i[1] = 0;
		while (i[1] < Tex_H * Tex_W)
		{
			info->texture[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

int	memory_plus2(t_info *info)
{
	int	i[2];

	i[0] = 0;
	info->path = (char **)malloc(sizeof(char *) * 4);
	if (!info->path)
		return (-1);
	while (i[0] < 4)
	{
		info->path[i[0]] = (char *)malloc(sizeof(char) * (Tex_H * Tex_W));
		if (!info->path[i[0]])
			return (-1);
		i[0]++;
	}
	i[0] = 0;
	while (i[0] < 4)
	{
		i[1] = 0;
		while (i[1] < Tex_H * Tex_W)
		{
			info->path[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

void	initialization(t_info *info)
{
	info->key.key_a = 0;
	info->key.key_w = 0;
	info->key.key_s = 0;
	info->key.key_d = 0;
	info->key.key_left = 0;
	info->key.key_right = 0;
	info->key.key_esc = 0;
	info->movespeed = 0.05;
	info->rotspeed = 0.05;
	info->zbuffer = (double *)malloc(sizeof(double) * width);
	info->buf = (int **)malloc(sizeof(int *) * height);
}

void	first_info(t_info *info)
{
	int	i;
	int	j;

	initialization(info);
	i = 0;
	while (i < height)
	{
		info->buf[i] = (int *)malloc(sizeof(int) * (height));
		i++;
	}
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	clean_img(t_img *img)
{
	img->img = 0;
	img->data = 0;
	img->img_height = 0;
	img->bpp = 0;
	img->size_l = 0;
	img->endian = 0;
	img->img_width = 0;
}
