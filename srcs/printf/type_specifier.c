#include "ft_printf.h"

char    *type_specifier(t_spec *spec, va_list *ap)
{
	char	*res;

	res = NULL;
	if (spec->type == 'c')
		type_c(res, ap);
	if (spec->type == 's')
		type_s(res, ap);
	if (spec->type == 'p')
		type_p(res, ap, spec);
	if (spec->type == 'o' || spec->type == 'u'
		|| spec->type == 'x' || spec->type == 'X')
		type_ouxX(res, spec, ap);
	if (spec->type == 'f')
		type_f(res, ap, spec);
	if (spec->type == 'i' || spec->type == 'd')
		type_id(res, ap, spec);
	return (res);
}

char	*type_ouxX(char *res, t_spec *spec, va_list *ap)
{
	int	nb;
	int	base;

	if (spec->type == 'o')
		base = 8;
	if (spec->type == 'u')
		base = 10;
	if (spec->type == 'x')
		base = 16;
	if (spec->type == 'X')
		base = 16;
	nb = va_arg(*ap, unsigned long long);
	if (spec->size[0] == 'h' && spec->size[1] == 'h')
		res = ft_itoa_base((short)nb, base, spec);
	if (spec->size[0] == 'h')
		res = ft_itoa_base((unsigned short int)nb, base, spec);
	if (spec->size[0] == 'l' && spec->size[1] == 'l')
		res = ft_itoa_base((unsigned long long)nb, base, spec);
	if (spec->size[0] == 'l')
		res = ft_itoa_base((unsigned long)nb, base, spec);
	else
		res = ft_itoa_base(nb, base, spec);
	return (res);
}

char	*type_c(char *res, va_list *ap)
{
	char	ch;

	res = (char*)malloc(2 * sizeof(char));
	ch = va_arg(*ap, int);
	res[0] = ch;
	res[1] = '\0';
	return (res);
}

char    *type_s(char *res, va_list *ap)
{
	char	*s;
	int		len;

    len = (int)ft_strlen((char *)res);
    res = (char*)malloc((len + 1) * sizeof(char));
    s = va_arg(*ap, char*);
    ft_strcpy(res, s);
	return (res);
}

char	*type_p(char *res, va_list *ap, t_spec *spec) //???
{
	int	nb;

	nb = va_arg(*ap, int);
	res = ft_itoa_base(nb, 16, spec);
	return (res);
}

char	*type_f(char *res, va_list *ap, t_spec *spec)
{
	long double	nb;

	if (spec->size[0] == 'L')
		nb = va_arg(*ap, long double);
	nb = va_arg(*ap, double);
	res = ft_fitoa(nb);
	return (res);
}

char    *type_id(char *res, va_list *ap, t_spec *spec)
{
	int	nb;
	
	nb = va_arg(*ap, long long);
	if (spec->size[0] == 'h')
		res = ft_itoa((short int)nb);
	if (spec->size[0] == 'l' && spec->size[1] == 'l')
		res = ft_itoa((long long)nb);
	if (spec->size[0] == 'l')
		res = ft_itoa((long)nb);
	if (spec->size[0] == 'h' && spec->size[1] == 'h')
		res = ft_itoa((char)nb);
	else
		res = ft_itoa(nb);
	return (res);
}
