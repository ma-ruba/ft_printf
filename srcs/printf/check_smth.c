#include "ft_printf.h"

int check_minus(char *res, char **point)
{
	int i;

	i = 0;
	while(res[i])
	{
		if (res[i] == '-')
		{
			*point = &res[i];
			return (1);
		}
		i++;
	}
	return (0);	
}

int check_plus(char *res, char **point)
{
	int i;

	i = 0;
	while(res[i])
	{
		if (res[i] == '+')
		{
			*point = &res[i];
			return (1);
		}
		i++;
	}
	return (0);	
}

int	check_space(char *res, char **point)
{

	int i;

	i = 0;
	while(res[i])
	{
		if (res[i] == ' ' && res[i - 1] != ' ' && res[i + 1] != ' ' && res[i + 1] != '\0')
		{
			*point = &res[i];
			return (1);
		}
		i++;
	}
	return (0);	
}

int check_0x(char *res, char **point)
{
	int i;

	i = 0;
	while(res[i])
	{
		if (res[i] == 'x' || res[i] == 'X')
		{
			*point = &res[i];
			return (1);
		}
		i++;
	}
	return (0);	
}
