#include "ft_printf.h"

char    *type_specifier(t_spec *spec, va_list *ap)
{
	char	*res;

	if (spec->type == 'c')
		type_c(res, ap);
	if (spec->type == 's')
		type_s(res, ap);
	if (spec->type == 'p')
		type_p(res, ap);
	if (spec->type == 'o' || spec->type == 'u' || spec->type == 'x' || spec->type == 'X')
		type_ouxX(res, spec, ap);
	if (spec->type == 'f')
		type_f(res, ap);
	if (spec->type == 'i' || spec->type == 'd')
		type_id(res, ap);
	return (res);
}

char	*type_ouxX(char *res, t_spec *spec, va_list *ap)
{
	int	nb;

	nb = va_atg(ap, int);
	if (spec->type == 'o')
		res = ft_itoa_base(nb, 8);
	if (spec->type == 'u')
		res = ft_itoa_base(nb, 10);
	if (spec->type == 'x')
		res = ft_itoa_base(nb, 16);
	if (spec->type == 'X')
		res = ft_itoa_base(nb, 16);
	return (res);
}

char	*type_ouxX(char *res, t_spec *spec, va_list *ap)
{
	char	ch;

	res = (char*)malloc(2 * sizeof(char));
	ch = va_arg(ap, char);
	res[0] = ch;
	res[1] = '\0';
	return (res);
}

char    *type_s(char *res, va_list *ap)
{
	char	*s;
	int		len;

    len = (int)ft_strlen(char *res);
    res = (char*)malloc((len + 1) * sizeof(char));
    s = va_arg(ap, char);
    ft_strcpy(res, s);
	return (res);
}

char	*type_p(char *res, va_list *ap) //???
{
	int	nb;

	nb = va_atg(ap, int);
	res = ft_itoa_base(nb, 16);
	return (res);
}

char	*type_f(char *res, va_list *ap)
{
	long double	nb;

	
}

char    *type_id(char *res, va_list *ap)
{
	int	nb;

	nb = va_atg(ap, int);
	res = ft_itoa(nb);
	return (res);
}
