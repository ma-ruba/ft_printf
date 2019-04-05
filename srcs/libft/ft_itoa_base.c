#include "ft_printf.h"

static size_t		ft_digits(long long num, int base)
{
	size_t i;

	i = 0;
	if (num == 0)
		i = 1;
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long num, int base, t_spec *spec)
{
	char		*str;
	long long	nb;
	size_t		i;

	nb = num;
	if (num == -9223372036854775807 - 1)
		str = "-9223372036854775808";
	i = ft_digits(num, base);
	if (num < 0)
		i++;
	if(!(str = ft_strnew(i)))
		return (NULL);
	if (num < 0)
		nb *= -1;
	while(i-- > 0)
	{
		if (num < 0 && i == 0)
			str[i] = '-';
		else if (nb % base < 10)
			str[i] = nb % base + '0';
		else if (spec->type == 'X')
			str[i] = nb % base + 55;
		else
			str[i] = nb % base + 87;      
		nb /= base;
	}
	return (str);
}
