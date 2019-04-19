#include "ft_printf.h"

char    *width_specifier(char *res, t_spec *spec)
{
	int		len;
	int		i;
	char	*ret;
	int		size;
	
	i = 0;
	len = (int)ft_strlen((char*)res);
	size = spec->width;
	if (zero)
	{
		len--;
		size++;
	}
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
