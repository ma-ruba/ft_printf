#include "ft_printf.h"

char    *width_specifier(char *res, t_spec *spec)
{
	int		len;
	int		i;
	char	*ret;
	int		size;
	
	i = 0;
	len = (int)ft_strlen((char*)res);
	if (zero)
		spec->width -= 1;
	size = spec->width;
	while (spec->flags[i])
	{
		if (spec->flags[i] == '-')
		{
			res = minus_flag(res, spec);
			return (res);
		}
		i++;
	}
	i = 0;
	if (len < spec->width)
	{
		if (!(ret = ft_strnew((int)size)))
			return (NULL);
		while (i < spec->width - len)
			ret[i++] = ' ';
		ft_strcpy(&ret[i], (char*)res);
		free((char*)res);
		return (ret);
	}
	return (res);
}
