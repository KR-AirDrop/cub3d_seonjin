#include "../cub3d.h"

int     memory_plus(t_info *info)
{
    int i;
    int j;

    i = 0;
    if (!(info->texture = (int**)malloc(sizeof(int*) * 11)))
        return (-1);
    while (i < 11)
    {
        if (!(info->texture[i] = (int*)malloc(sizeof(int) * (texHeight * texWidth))))
            return (-1);
        i++;
    }
    i = 0;
    while (i < 11)
    {
        j = 0;
        while (j < texHeight * texWidth)
        {
            info->texture[i][j] = 0;
            j++;
        }
        i++;
    }
    return (0);
}

int     memory_plus2(t_info *info)
{
    int i;
    int j;

    i = 0;
    if (!(info->path = (char**)malloc(sizeof(char*) * 4)))
        return (-1);
    while (i < 4)
    {
        if (!(info->path[i] = (char*)malloc(sizeof(char) * (texHeight * texWidth))))
            return (-1);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < texHeight * texWidth)
        {
            info->path[i][j] = 0;
            j++;
        }
        i++;
    }
    return (0);
}

void    initialization(t_info *info)
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
    info->zbuffer = (double*)malloc(sizeof(double) * width);
    info->buf = (int**)malloc(sizeof(int*) * height);
}

void    first_info(t_info *info)
{
    int i;
    int j;

    initialization(info);
    i = 0;
    while (i < height)
    {
        info->buf[i] = (int*)malloc(sizeof(int) * (height));
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

void clean_img(t_img *img)
{
    img->img = 0;
    img->data = 0;
    img->img_height = 0;
    img->bpp = 0;
    img->size_l = 0;
    img->endian = 0;
    img->img_width = 0;
}