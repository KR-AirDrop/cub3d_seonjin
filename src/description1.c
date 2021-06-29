#include "../cub3d.h"

int     config_color(char location, char *line, t_info *info)
{
    int i;
    int r;
    int g;
    int b;
    int color;

    i = 0;
    r = 0;
    g = 0;
    b = 0;
    while (is_space(line[i]))
        i++;
    while (line[i] && ft_isdigit(line[i]))
    {
        r = r * 10 + (line[i] - '0');
        i++;
    }
    i++;
    while (line[i] && ft_isdigit(line[i]))
    {
        g = g * 10 + (line[i] - '0');
        i++;
    }
    i++;
    while (line[i] && ft_isdigit(line[i]))
    {
        b = b * 10 + (line[i] - '0');
        i++;
    }
    color = (r * 256 * 256) + (g * 256) + b;
    put_rgb(location, info, color);
    return (1);
}

int     config_path(int index, char *line, t_info *info)
{
    int     start;
    int     end;
    char    *path;

    start = 0;
    while (is_space(line[start]))
        start++;
    end = ft_strlen(line);
    path = ft_substr(line, start, end - start);
    if (!path || !file_exists(path))
        return (-1);
    info->path[index] = path;
    return (1);
}

void    put_rgb(char location, t_info *info, int color)
{
    if (location == 'F')
        info->floor_color = color;
    else if (location == 'C')
        info->ceiling_color = color;
}