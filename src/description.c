#include "../cub3d.h"

int     treat_description(char *file_name,t_info *info)
{
    int fd;
    int gnl_return;
    char *line;
    
    if (!file_name_check(file_name))
        return (0);
    if (!(fd = open(file_name,O_RDONLY)))
        return (-1);
    while((gnl_return = get_next_line(fd, &line)) ==1) ///********* 고쳐야 하는 부분 ****//
    {
        if(!parse_line(line, info))
        {
            printf("ㅠㅠ");
            return(0);
        }
        free(line);
    }
    close(fd);
  
    return(1);
}
/*
int     parse_line(char *line, t_info *info)
{
    int i;
    int line_length;
    


    line_length = ft_strlen(line);

    //if (line_length == 0)
    //    return (0);
    i = 0;
    while (line[i] != '\0')
    {
        if (is_space(line[i]))
            i++;
    
        else if (is_type_identifier(line[i], line[i + 1], line, info))
            break;
        else if (is_map_character(line[i]))//,info))
        {
          
                i += save_map1(line, info);
           
        }
        else
        {
            printf("something error\n");
            return(0);
        }
    }
    return(1);
}

*/
int     parse_line(char *line , t_info *info)
{
    int i;
    int num = 0;

    i = 0;
    while (line[i] != '\0')
    {
        if (is_space(line[i]))
        {
            i++;
            num++;
        }
        else if (is_type_identifier(line[i], line[i + 1], line, info))
            break;
        else if (is_map_character(line[i]))
            i = i + save_map1(line, info) - num;
        else
            return (0);  
    }
    return (1);
}

int     is_type_identifier(char a, char b, char *line, t_info *info)
{
  
    if ((( a == 'F' || a == 'C') && is_space(b)))
    {
      
            config_color(a, line + 1, info);
    }
    else if (a == 'N' && b == 'O')
        config_path(0, line + 2, info);
    else if (a == 'S' && b == 'O')
        config_path(1, line + 2, info);
    else if (a == 'W' && b == 'E')
        config_path(2, line + 2, info);
    else if (a == 'E' && b == 'A')
        config_path(3, line + 2, info);
    else
        return(0);
    return(1);
}

int     check_line(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if(line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
            i++;
        else
        {
            printf("Something Wrong\n");
            return(0);
        }
    }
    return (1);
}