#include "ft_printf.h"

int		ft_find_specifier(const char *format)
{
	int	i;

	i = 0;
	if (format[i] == '%' && format[i + 1] != '%')
		return (1);
	return (0);
}

int	exeption(char const *format)
{
	int	i;

	i = 0;
	if ((format[i] == '%' && format[i + 1] == '%')
		return (1);
	else
		return (0);
}

void	ft_process_specifier(const char *format, int *ret, int *i)
{
	int	dot;

	dot = 0;
	(*i)++;
	while (format[*i] && (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' ||
			format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'o' ||
			format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X'))
	{
		if (format[*i] == '.')
			dot = 1;
		(*i)++;
	}
	type_specifier(&format[*i], );
	(*i)--;
	if (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j'
		|| format[*i] == 'z' || format[*i] == 't' || format[*i] == 'L')
		size_specifier(format[*i], );
	(*i)--;
	if (format[*i] == 'l' || format[*i] == 'h')
		(*i)--;
	if (dot)
	{
		while(format[*i] != '.')
			(*i)--;
		width_specifier();
	}
	(*i)--;
	
}

void	ft_print_and_smth(const char *format, va_list *ap, int *ret) //23
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (ft_find_specifier(format))
			ft_process_specifier(format, ret, &i);
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
	ft_print_and_smth(format, &ap, ret);
	va_end(ap);
	return (*ret);
}
