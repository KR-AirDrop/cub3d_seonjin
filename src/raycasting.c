#include "../cub3d.h"

void	calc(t_info *info)
{
	int	x;
    t_calac_data data;

	x = 0;
	while (x < width)
	{
		data.camera_x = 2 * x / (double)width - 1;
		data.raydir_x = info->dir_x + info->plane_x * data.camera_x;
		data.raydir_y = info->dir_y + info->plane_y * data.camera_x;
		data.map_x = (int)info->pos_x;
		data.map_y = (int)info->pos_y;
		data.deltadist_x = fabs(1 / data.raydir_x);
		data.deltadist_y = fabs(1 / data.raydir_y);
		data.hit = 0;
        ray_plus(&data, info);
        hit_check(&data, info);
        textured_input(&data, info);
        calc_color(info, &data, x);
        x++;
    }


}

void    calc_color(t_info *info, t_calac_data *data,int x)
{
    int y;

    if (data->side == 0 || data->side == 1)
		data->wall_x = info->pos_y + data->perpwalldist * data->raydir_y;
	else
		data->wall_x = info->pos_x + data->perpwalldist * data->raydir_x;
	data->wall_x -= floor(data->wall_x);
    data->tex_x = (int)(data->wall_x * (double)texWidth);
	if (data->side == 0 && data->raydir_x > 0)
		data->tex_x = texWidth - data->tex_x - 1;
	if (data->side == 1 && data->raydir_y < 0)
		data->tex_x = texWidth - data->tex_x - 1;
	data->step = 1.0 * texHeight / data->lineheight;
	data->texPos = (data->drawstart - height / 2 + data->lineheight / 2) * data->step;
    y = data->drawstart;
	while (y < data->drawend)	
	{
        data->tex_y = (int)data->texPos & (texHeight - 1);
		data->texPos += data->step;
		data->color = info->texture[data->texnum][texHeight * data->tex_y + data->tex_x];
        if (data->side == 0 || data->side == 1 || data->side == 2|| data->side == 3)
			data->color = info->texture[data->texnum][texHeight * data->tex_y + data->tex_x];
		info->buf[y][x] = data->color;
        y++;
	}
    info->zbuffer[x] = data->perpwalldist;
}

void    hit_check(t_calac_data *data, t_info *info)
{
    while (data->hit == 0)
	{
		if (data->sidedist_x < data->sidedist_y)
		{
			data->sidedist_x += data->deltadist_x;
			data->map_x += data->step_x;
            if (data->step_x == 1)
                data->side = 0;
			else if (data->step_x == -1)
                data->side = 1;
        }
		else
		{
			data->sidedist_y += data->deltadist_y;
			data->map_y += data->step_y;
			if (data->step_y == 1)
                data->side = 2;
            else if (data->step_y == -1)
                data->side = 3;
		}
		if (info->map[data->map_x][data->map_y] == '1')
            data->hit = 1;
	}
}

void    textured_input(t_calac_data *data, t_info *info)
{
    if (data->side == 0 || data->side == 1)
		data->perpwalldist = (data->map_x - info->pos_x + (1 - data->step_x) / 2) / data->raydir_x;
	else
		data->perpwalldist = (data->map_y - info->pos_y + (1 - data->step_y) / 2) / data->raydir_y;
	data->lineheight = (int)(height / data->perpwalldist);
	data->drawstart = -data->lineheight / 2 + height / 2;
	if(data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + height / 2;
	if (data->drawend >= height)
		data->drawend = height - 1;
    if (info->map[data->map_x][data->map_y] == '1' && data->side == 0)
       data->texnum = 0;
    else if (info->map[data->map_x][data->map_y] == '1' && data->side == 1)
        data->texnum = 1;
    else if (info->map[data->map_x][data->map_y] == '1' && data->side == 2)
        data->texnum = 2;
    else if (info->map[data->map_x][data->map_y] == '1' && data->side == 3)
        data->texnum = 3;
}

void    ray_plus(t_calac_data *data, t_info *info)
{
    if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->sidedist_x = (info->pos_x - data->map_x) * data->deltadist_x;
	}
	else
	{
		data->step_x = 1;
		data->sidedist_x = (data->map_x + 1.0 - info->pos_x) * data->deltadist_x;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->sidedist_y = (info->pos_y - data->map_y) * data->deltadist_y;
	}
	else
	{
		data->step_y = 1;
		data->sidedist_y = (data->map_y + 1.0 - info->pos_y) * data->deltadist_y;
	}
}