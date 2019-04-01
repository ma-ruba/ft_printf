#include "ft_printf.h"

char    *precise_specifier(char *c, char *res, t_type *type)
{
	char    *ret;

	if (type->ch == 'f')
		ret = f_precise(c, res);
	if (type->ch == 's')
		ret = s_precise(c, res);
	else
	{
		
	}
	return (ret);
}

char    *s_precise(char *c, char *res)
{
	int     i;
	int     precise;
	char    *ret;

	i = 0;
	precise = ft_atoi((char*)c);
	if ((int)ft_strlen((char*)res) > precise)
	{
		if (!(ret = ft_strnew((int)precise)))
			return (NULL);
		ft_strncpy(ret, (char*)res, (int)precise);
		free((char*)res);
	}
	return (ret);
}

char    *f_precise(char *c, char *res)
{
   int     i;
   int     precise;
   char    *ret;
   int     count;

	i = 0;
	count = 0;
	precise = ft_atoi((char*)c);
	while (res[i] != '.')
			i++;
	if ((int)ft_strlen((char*)res[++i]) < precise)
	{
		if (!(ret = ft_strnew((int)precise)))
			return (NULL);
		while (res[i])
		{
			i++;
			count++;
		}
		ft_strncpy(ret, (char*)res, (int)precise);
		ft_memset((char*)ret[i], '0', (int)(precise - count));
		free((char*)res);
	}
	return (ret);
}
