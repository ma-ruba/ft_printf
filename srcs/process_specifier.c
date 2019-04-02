#include "ft_printf.h"

void	process_specifier(char *format, va_list *ap)
{
	int		dot;
	int		j;
	char	*res;
	t_spec  spec;
	int		count_flag;

	dot = 0;
	count_flag = 0;
	find_width_param(format[i], ap, &spec);
	while (format[i] && (format[i] == 'c' || format[i] == 's' || format[i]
			== 'p' || format[i] == 'd' || format[i] == 'i' || format[i] ==
			'o' || format[i] == 'u' || format[i] == 'x' || format[i] == 'X'
			|| format[i] == 'f'))
	{
		if (format[i] == '.')
			dot = 1;
		if (format[i + 1] == '*')
			spec.precision = va_arg(ap, int);
		i++;
	}
	j = i;
	i++;
	res = type_specifier(&format[j], ap, &spec);
	format[j--] = '\0';
	if (format[j] == 'h' || format[j] == 'l' || format[j] == 'L')
	{
		if (format[j - 1] == 'l' || format[j - 1] == 'h')
			j--;
		size_specifier(format[j], res);
		format[j] = '\0';
	}
	if (dot)
	{
		while(format[j] != '.')
			j--;
		res = precise_specifier(format[j + 1], res, &type);
		format[j] = '\0';
	}
	while (format[j - 1] != '%')
		j--;
	while (format[j] == '0' || format[j] == '#' || format[j] == '+'
			|| format[j] == '-'))
	{
		flag_specifier(&format[j], res, &spec, &count_flag);
		j++;
		count_flag++:
	}
	if ((format[j] <= '9' && format[j] >= '1') || format[j] == '*')
		width_specifier(format[j], res, &spec);
	print_param(res);
	free((char*)res);
}

void	find_width_param(char *format, va_list *ap, t_spec *spec)
{
	int	j;

	j = 1;
	while (format[j] == '0' || format[j] == '#' || format[j] == '+'
			|| format[j] == '-'))
		j++;
	if (format[j] == '*')
		spec->width = va_arg(ap, int);
}

void    print_param(char *res)
{
	int i;

	i = 0;
	while (res[i])
	{
		write(1, &res[i], 1);
		i++;
		ret++;
	}
}
