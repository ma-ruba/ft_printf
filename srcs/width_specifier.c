#include "ft_printf.h"

void    width_specifier(char *c, char *res, t_spec *spec)
{
	int	len;
	int	i;
	
	i = 0;
	len = (int)ft_strlen((char*)res);
	if (*c != '*')
		spec->width = ft_atoi((char*)c);
	if (len < spec->width)
	{
		if (!(ret = ft_strnew((int)width->precision)))
			return (NULL);
		while (i < spec->width - len)
			ret[i] = ' ';
		ft_strcpy(ret[i], (char*)res);
		return (ret);
	}
	return (res);
}
