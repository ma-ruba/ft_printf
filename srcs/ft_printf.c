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
	(*i)++;
	
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
