#include "ft_printf.h"

char	*flag_specifier(char *res, t_spec *spec, int flag)
{
	if (spec->flags[flag] == '0')
		res = zero_flag(res, spec);
	else if (spec->flags[flag] == '-')
		res = minus_flag(res, spec);
	else if (spec->flags[flag] == '+')
		res = plus_flag(res, spec);
	else if (spec->flags[flag] == '#')
		res = hash_flag(res, spec);
	else if (spec->flags[flag] == ' ')
		res = space_flag(res, spec);
	return (res);
}

char	*zero_flag(char *res, t_spec *spec)
{
	int		len;
	int		i;

	i = 0;
	if (g_zero)
		spec->width -= 1;
	len = (int)ft_strlen((char*)res);
	while (spec->flags[i])
	{
		if (spec->flags[i] == '-')
			return (res);
		i++;
	}
	if (((spec->type == 'i' || spec->type == 'd' || spec->type == 'u'
		|| spec->type == 'o' || spec->type == 'X' || spec->type == 'x')
		&& spec->precision == -1) || spec->type == 'f' || spec->type == 'p' ||
		spec->type == 's' || spec->type == 'c' || spec->type == '%')
	{
		if (len < spec->width)
			return (zero_flag2(&res, spec, len));
	}
	return (res);
}

char	*zero_flag2(char **res, t_spec *spec, int len)
{
	char	*ret;
	int		size;

	size = spec->width;
	if (!(ret = ft_strnew((int)size)))
		return (NULL);
	ft_memset(ret, '0', spec->width - len);
	ft_strcpy(&ret[(spec->width) - len], (char*)res[0]);
	free((char*)res[0]);
	return (ret);
}

char	*minus_flag(char *res, t_spec *spec)
{
	int		len;
    char 	*ret;
	int		size;
	
    len = (int)ft_strlen((char*)res);
	size = spec->width;
	if (spec->precision > spec->width)
        return (res);
	if (len < spec->width)
	{
		if (!(ret = ft_strnew((int)size)))
			return (NULL);
		ft_strcpy(&ret[0], (char*)res);
		ft_memset((void*)(&ret[len]), ' ', spec->width - len);
		free((char*)res);
		return (ret);
	}
	return (res);
}

char	*plus_flag(char *res, t_spec *spec)
{
	int		len;
	char	*point;

	point = NULL;
	len = (int)ft_strlen((char*)res);
	if (spec->type == 'i' || spec->type == 'd')
	{
		if (!check_minus(res, &point))
		{
			if (spec->precision == -1 && res[0] == '0' && res[1] != ' ' &&
			res[1] != '\0')
			{
				res[0] = '+';
				return (res);
			}
			if (res[len - 1] == ' ')
				return (plus_flag2(res, &len));
			else
				return (plus_flag3(res, &len));
		}
	}
	return (res);
}

char	*plus_flag2(char *res, int *len)
{
	char	*ret;

	if (!(ret = ft_strnew((int)len[0])))
		return (NULL);
	ft_strncpy(&ret[1], res, (int)len[0] - 1);
	ret[0] = '+';
	free((char*)res);
	return (ret);
}

char	*plus_flag3(char *res, int *len)
{
	char	*ret;

	if (!(ret = ft_strnew((int)len[0] + 1)))
		return (NULL);
	ret[0] = '+';
	ft_strcpy(&ret[1], (char*)res);
	free((char*)res);
	return (ret);
}

char	*hash_flag(char *res, t_spec *spec)
{
	int		len;
	char	*ret;

	ret = NULL;
	len = (int)ft_strlen((char*)res);
	if (spec->type == 'o')
	{
		if (res[len - 1] == ' ')
		{
			if (!(ret = ft_strnew(len)))
				return (NULL);
			ft_strncpy(&ret[1], res, len - 1);
			ret[0] = '0';
			free((char*)res);
			return (ret);
		}
		else
			return (hash_flag_else(res, spec, len));
	}
	if (spec->type == 'x' || spec->type == 'X')
		return (hash_flag_forx_bigx(res, spec, &len));
	return (res);
}

char	*hash_flag_forx_bigx(char *res, t_spec *spec, int *len)
{
	char	*ret;

	if (res[0] == '0')
		return (res);
	if (!(ret = ft_strnew((int)len[0] + 2)))
		return (NULL);
	ret[0] = '0';
	if (spec->type == 'x')
		ret[1] = 'x';
	if (spec->type == 'X')
		ret[1] = 'X';
	ft_strcpy(&ret[2], (char*)res);
	free((char*)res);
	return (ret);
}

char	*hash_flag_else(char *res, t_spec *spec, int len)
{
	char	*ret;

	if (res[0] == '0' && res[1] == '\0' && spec->precision == -1)
		return (res);
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	ret[0] = '0';
	ft_strcpy(&ret[1], (char*)res);
	free((char*)res);
	return (ret);
}

char	*space_flag(char *res, t_spec *spec)
{
	int		len;
    char	*ret;
	int		i;
	char	*point;

	i = 0;
	point = NULL;
	while (spec->flags[i])
	{
		if (spec->flags[i] == '+' && !check_zero(res))
			return (res);
		i++;
	}
    len = (int)ft_strlen((char*)res);
	if (spec->type == 'd' || spec->type == 'f' || spec->type == 'i')
	{
		if (!check_minus(res, &point))
		{
			if (res[0] == '0' && res[1] != '\0' && spec->precision == -1)
			{
				res[0] = ' ';
				return (res);
			}
			if (!(ret = ft_strnew(len + 1)))
				return (NULL);
            ret[0] = ' ';
			ft_strcpy(&ret[1], (char*)res);
			free((char*)res);
			return (ret);
		}
	}
	return (res);
}
