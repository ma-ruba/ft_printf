#include "ft_printf.h"

char    *type_specifier(t_spec *spec, va_list *ap)
{
	char	*res;

	if (spec->type == 'c')
		type_c(res, ap);
	if ( == 's')
		type_s(char *format);
	if (format[*i] == 'p')
		type_p(char *format);
	if (format[*i] == 'd')
		type_d(char *format);
	if (format[*i] == 'i')
		type_i(char *format);
	if (format[*i] == 'o')
		type_o(char *format);
	if (format[*i] == 'u')
		type_u(char *format);
	if (format[*i] == 'x')
		type_x(char *format);
	if (format[*i] == 'X')
		type_X(char *format);
	return ();
}

char    *type_c(char *res, va_list *ap)
{
	char	ch;

	//res = ft_strnew(1);
	res = (char*)malloc(2 * sizeof(char));
	ch = va_arg(ap, char);
	res[0] = ch;
	res[1] = '\0';
	return (res);
}

{
	char	*s;


}

char    *type_i(char *to_print, int   *ret)
{
	int	nb;

	nb = va_atg(ap, int);
	ft_itoa(nb);
}
