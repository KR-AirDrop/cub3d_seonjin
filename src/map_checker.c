
#include "../cub3d.h"

/* 완전 탐색으로 맵을 검사한다 */
int	check_map(char **map, int x, int y, int *p)
{
	int i;
	int	g_dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; //서, 남, 동, 북, 북서, 남서, 남동, 북동
	int	g_diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};

	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == 'W' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'N')
		*p = 1;
	if (map[y][x] == ' ')	//공백을 만나 0 return
		return (0);
	map[y][x] = 'x';	//이미 방문한 곳은 x로 체크
	/* 0을 만나 함수를 재귀 호출 */
	i = -1;
	while (++i < 8)
		if (check_map(map, x + g_dirx[i], y + g_diry[i], p) == 0) //g_dirx와 g_diry로 8방향 이동
			return (0);
	return (1);
}

/* seg fault 방지를 위해, 맵의 테두리를 ' '공백으로 감싼다 */
char	**init_map(char **map)
{
	int		x;
	int		y;
	char	**test_map;
	/* 테두리 공간을 확보하기 위해 가로,세로가 2씩 큰 맵 생성 */
	if (!(test_map = (char **)malloc(sizeof(char *) * 103)))
		return (0);
	test_map[102] = 0;	//null
	y = -1;
	while (++y < 102)
	{
		if (!(test_map[y] = (char *)malloc(sizeof(char) * 103)))
			return (0);
		test_map[y][102] = 0;	//null
		x = -1;
		while (++x < 102)
			test_map[y][x] = ' ';	//공백으로 채움
	}
	/* 테두리는 공백으로 남겨두고, (1, 1)부터 map데이터를 채움 */
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			test_map[y + 1][x + 1] = map[y][x];
	}
	return (test_map);
}

/* char **를 free하는 함수 */
int		free_map(char **map, int cnt)
{
	while (cnt >= 0)
	{
		free(map[cnt]);
		cnt--;
	}
	free(map);
	return (0);
}

int	map_checker(t_info *info)
{
	int		x, y, p;
	int		is_zero;
	char	**test_map;
	/* 테스트 시작 */
	test_map = init_map(info->map);
	is_zero = 0;
	p = 0;
	y = -1;
	while (test_map[++y])
	{
		x = -1;
		while (test_map[y][++x])
			if (test_map[y][x] == '0')	//'0'을 만나면 검사 시작
			{
				is_zero = 1;
				if (check_map(test_map, x, y, &p) == 0)
				{
					write(1, "Map check : ERROR\n", 19);
					free_map(test_map, 103);
					return (0) ;
				}
			}
	}
	if (is_zero == 0)
    {
		write(1, "No place\n", 9);
        return (0);
    }
	if (info->player_num != 1)
	{
		printf("player num error (%d)\n",info->player_num);
		return (0);
	}
	if (p == 0)
	{
		printf("player out\n");
		return (0);
	}
	write(1, "Map check : OK\n", 15);
	free_map(test_map, 103);
	return (1);
}