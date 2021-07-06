/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:45:31 by seonchoi          #+#    #+#             */
/*   Updated: 2021/07/06 17:31:33 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_loop(t_info *info)
{
	floar_casting(info);
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}

int	main2(t_info *info)
{
	split_map(info);
	first_info(info);
	if (!(map_checker(info)))
		return (0);
	memory_plus(info);
	info->mlx = mlx_init();
	load_texture(info);
	return (1);
}

int	main3(t_info *info)
{
	memory_plus2(info);
	info->tmp = (char *)malloc(sizeof(char) * 1);
	if (!info->tmp)
		return (0);
	info->tmp[0] = '\0';
	info->player_num = 0;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 2)
	{
		if (!main3(&info))
			return (0);
		if (treat_description(argv[1], &info))
		{
			if (!(main2(&info)))
				return (0);
			info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "mlx");
			info.img.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
			info.img.data = (int *)mlx_get_data_addr(info.img.img,
					&info.img.bpp, &info.img.size_l, &info.img.endian);
			mlx_loop_hook(info.mlx, &main_loop, &info);
			mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
			mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
			mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &cub_exit, 0);
			mlx_loop(info.mlx);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
