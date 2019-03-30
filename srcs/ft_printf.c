#include "ft_printf.h"

int		find_specifier(const char *format)
{
	int	i;

	i = 0;
	if (format[i] == '%' && format[i + 1] != '%')
		return (1);
	return (0);
}

int		exeption(char const *format)
{
	int	i;

	i = 0;
	if ((format[i] == '%' && format[i + 1] == '%')
		return (1);
	else
		return (0);
}

void	process_specifier(char *format, int *ret, int *i)
{
	int	dot;

	dot = 0;
	(*i)++;
	while (format[*i] && (format[*i] == 'c' || format[*i] == 's' || format[*i]
			== 'p' || format[*i] == 'd' || format[*i] == 'i' || format[*i] ==
			'o' || format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X'))
	{
		if (format[*i] == '.')
			dot = 1;
		(*i)++;
	}
	type_specifier(&format[*i], );
	(*i)--;
	if (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j'||
		format[*i] == 'z' || format[*i] == 't' || format[*i] == 'L')
	{
		size_specifier(format[*i], );
		if (format[*i - 1] == 'l' || format[*i - 1] == 'h')
			(*i)--;
		format[*i] = '\0';
	}
	if (dot)
	{
		while(format[*i] != '.')
			(*i)--;
		precise_specifier(ft_atoi((char*)format[*i + 1], );
		format[*i] = '\0';
	}
	while (format[*i] != '%' || format[*i] != '0' || format[*i] != '#' ||
			format[*i] != '+' || format[*i] != '-')
			(*i)--;
		width_specifier(ft_atoi((char*)format[*i + 1], );
	                                        
}

void	print_and_smth(const char *format, va_list *ap, int *ret) //25
{
	int		i;
	char	*copy;

	copy = ft_strcpy(copy, (char*)format);
	i = 0;
	while (format[i])
	{
		if (find_specifier(format))
			process_specifier(copy, ret, &i);
		else
		{
			if (exeption(format))
			{
				write(1, '%', 1);
				i += 2;
				(*ret)++;
			}
			else
			{
				write(1, &format[i], 1);
				i++;
				(*ret)++;
			}
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		*ret;

	*ret = 0;
	va_start(ap, format);
	print_and_smth(format, &ap, ret);
	va_end(ap);
	return (*ret);
}
