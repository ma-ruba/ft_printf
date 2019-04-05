#include "ft_printf.h"

void	process_specifier(char *format, va_list *ap)
{
    int		dot;
	int		j;
	t_spec  spec;
	int		k;
	int		flag;

	dot = 0;
	flag = 0;
	k = 0;
	find_width_param(&format[i + 1], ap, &spec);
	while (format[i] && (format[i] == 'c' || format[i] == 's' || format[i]
			== 'p' || format[i] == 'd' || format[i] == 'i' || format[i] ==
			'o' || format[i] == 'u' || format[i] == 'x' || format[i] == 'X'
			|| format[i] == 'f'))
	{
		if (format[i] == '.')
			dot = 1;
		i++;
	}
	spec.type = format[i];
	j = i;
	i++;
	format[j--] = '\0';
	if (format[j] == 'h' || format[j] == 'l' || format[j] == 'L')
	{
		if (format[j - 1] == 'l' || format[j - 1] == 'h')
			j--;
		spec.size = &format[j];
		format[j] = '\0';
	}
	else
		spec.size = NULL;
	if (dot)
	{
		while(format[j] != '.')
			j--;
		if (format[j + 1] == '*')
			spec.precision = va_arg(*ap, int);
		if (format[j + 1] == '\0')
			spec.precision = 0;
		else
			spec.precision = ft_atoi((char*)(&format[j + 1]));
		format[j] = '\0';
	}
	else
		spec.precision = -1;
	while (format[j - 1] != '%')
		j--;
	while (format[j] == '0' || format[j] == '#' || format[j] == '+'
			|| format[j] == '-')
	{
		while (k < 5)
		{
			if (spec.flags[k] == format[j])
				break ;
		}
		if (k == 5)
		{
			spec.flags[flag] = format[j];
			flag++;
		}
		j++;
		k = 0;
	}
	if (format[j] <= '9' && format[j] >= '1')
		spec.width = ft_atoi((char*)(&format[j]));	
	call_specifier(ap, &spec, flag);
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

void	find_width_param(char *format, va_list *ap, t_spec *spec)
{
	int	j;

	j = 0;
	while (format[j] == '0' || format[j] == '#' || format[j] == '+'
			|| format[j] == '-')
		j++;
	if (format[j] == '*')
		spec->width = va_arg(*ap, int);
}

void    call_specifier(va_list *ap, t_spec *spec, int flag)
{
	char	*res;
	int		count;

	count = 0;
	res = type_specifier(spec, ap);
	if (spec->precision != -1)
		res = precise_specifier(res, spec);
	
	if (spec->width != -1)
		res = width_specifier(res, spec);
	while (count < flag)
	{
		res = flag_specifier(res, spec, flag);
		count++;
	}
	print_param(res);
	free((char*)res);
}