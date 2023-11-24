#include "cub3d.h"

int	is_path(char c)
{
	if ((c == ',') || (c >= 'a' && c <= 'z')
		|| (c >= 0 && c <= 9)
		|| (c >= 'A' && c <= 'Z')
		|| (c == '.' || c == '/'))
			return (1);
	return (0);
}

int	is_str_num(char c)
{
	if (c == ',' || (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}

int	find_str_in_str(char *str1, char *str2)
{
	int i;
	int j;
	int x;
	
	i = 0;
	j = 0;
	x = 0;
	while (str1[i])
	{
		if (str1[i] == str2[x])
		{
			j = i;
			while (str1[i] == str2[x])
			{
				x++;
				j++;
				i++;
			}
			return (j);
		}
		i++;
	}
	return (0);
}

int	mod_uns_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			wrong_value();
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}
