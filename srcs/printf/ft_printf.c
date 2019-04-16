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
	if ((format[i] == '%' && format[i + 1] == '%'))
		return (1);
	else
		return (0);
}

void	print_and_smth(const char *format, va_list *ap) //25
{
	char	*copy;
	size_t		len;

	len = ft_strlen(format);
	copy = ft_strnew(len);
	ft_strcpy(copy, format);
	i = 0;
	while (format[i])
	{
		if (find_specifier(&format[i]))
			process_specifier(copy, ap);
		else
		{
			if (exeption(format))
			{
				write(1, "%", 1);
				i += 2;
				ret++;
			}
			else
			{
				write(1, &format[i], 1);
				i++;
				ret++;
			}
		}
	}
	free((char*)copy);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	print_and_smth(format, &ap);
	va_end(ap);
	return (ret);
}
