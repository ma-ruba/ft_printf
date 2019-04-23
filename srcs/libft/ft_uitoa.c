#include "ft_printf.h"

static size_t		ft_digits(unsigned long long num)
{
	size_t i;

	i = 0;
	if (num == 0)
		i = 1;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned long long num)
{
	char		        *str;
	size_t		        i;

	i = ft_digits(num);
	if(!(str = ft_strnew(i)))
		return (NULL);
	while(i-- > 0)
	{
		str[i] = num % 10 + '0';     
		num /= 10;
	}
	return (str);
}
