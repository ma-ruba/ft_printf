#include "ft_printf.h"

char		*width_specifier(char *res, t_spec *spec)
{
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen((char*)res);
	if (g_zero)
		spec->width -= 1;
	while (spec->flags[i])
	{
		if (width_specifier2(&res, spec, &i))
			return (res);
	}
	i = 0;
	if (len < spec->width)
		return (width_specifier3(&res, spec, &i, len));
	return (res);
}

int		width_specifier2(char **res, t_spec *spec, int *i)
{
	int	flag;
	
	flag = 0;
	if (spec->flags[*i] == '-')
	{
		res[0] = minus_flag(res[0], spec);
		flag = 1;
	}
	if (spec->flags[*i] == '0' && (spec->type == 'o' || spec->type == 's'))
	{
		res[0] = zero_flag(res[0], spec);
		flag = 1;
	}
	(*i)++;
	return (flag);
}

char		*width_specifier3(char **res, t_spec *spec, int *i, int len)
{
	int		size;
	char	*ret;

	size = spec->width;
	if (!(ret = ft_strnew((int)size)))
			return (NULL);
	while (*i < spec->width - len)
		ret[(*i)++] = ' ';
	ft_strcpy(&ret[*i], (char*)res[0]);
	free((char*)res[0]);
	return (ret);
}
