#include "cub3d.h"

t_map	find_so(t_map	map)
{
	int i;
	int x;
	int j;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "SO");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_path(map.mat[i][j]) == 1))
				j++;
			map.so = ft_substr(map.mat[i], x, j);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		args_notfound();
	return (map);
}

t_map	find_we(t_map	map)
{
	int i;
	int x;
	int j;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "WE");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_path(map.mat[i][j]) == 1))
				j++;
			map.we = ft_substr(map.mat[i], x, j);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		args_notfound();
	return (map);
}

t_map	find_ea(t_map	map)
{
	int i;
	int x;
	int j;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "EA");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_path(map.mat[i][j]) == 1))
				j++;
			map.ea = ft_substr(map.mat[i], x, j);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		args_notfound();
	return (map);
}

t_map	find_no(t_map	map)
{
	int i;
	int x;
	int j;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "NO");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_path(map.mat[i][j]) == 1))
				j++;
			map.no = ft_substr(map.mat[i], x, j);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		args_notfound();
	return (map);
}

t_map	find_f(t_map	map)
{
	int i;
	int x;
	int j;
	char	*f_c;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "F");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			j++;
			while ((is_str_num(map.mat[i][j]) == 1))
			{
				j++;
				if (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
					wrong_format();
			}
			f_c = ft_substr(map.mat[i], x, j);
			map.f_color = color_values(f_c);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		color_notfound();
	return (map);
}

t_map	find_c(t_map	map)
{
	int i;
	int x;
	int j;
	char	*f_c;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "C");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_str_num(map.mat[i][j]) == 1))
			{
				j++;
				if (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
					wrong_format();
			}
			f_c = ft_substr(map.mat[i], x, j);
			map.c_color = color_values(f_c);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		color_notfound();
	return (map);
}

int *color_values(char *str)
{
	int 	i;
	int		*_color;
	char 	**nums;

	i = 0;
	nums = ft_split(str, ',');
	_color = (int *)malloc(4 * sizeof(int));
	while (nums[i])
	{

		_color[i] = mod_uns_atoi(nums[i]);
		if (i >= 3)
			wrong_value();
		i++;
	}
	if (i <= 2)
		wrong_value();
	return (_color);
}