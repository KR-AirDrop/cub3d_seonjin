#include "cub3d.h"

int	main_loop(t_info *info)
{
    floar_casting(info);
	calc(info);
	draw(info);
    key_update(info);
	return (0);
}

int main(int argc, char *argv[])
{
    t_info info;


    if (argc == 2)
    {
       // printf("a");
        memory_plus2(&info);
        info.tmp = (char*)malloc(sizeof(char) * 1);
        info.tmp[0] = 'a';
        info.tmp[1] = '\0';
        info.player_num = 0;
        if(treat_description(argv[1],&info))
        {
            split_map(&info);
            first_info(&info);
            if(!(map_checker(&info)))
                return(0);
            memory_plus(&info);
            info.mlx = mlx_init();
            load_texture(&info);
	        info.win = mlx_new_window(info.mlx, width, height, "mlx");
	        info.img.img = mlx_new_image(info.mlx,width, height);
	        info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	        mlx_loop_hook(info.mlx, &main_loop, &info);
	        mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	        mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	        mlx_loop(info.mlx);
        }
    }
    else if (argc < 2)
        printf("Error\n");
    else
        printf("Too many argument Error\n");
        
     
}