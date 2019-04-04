#include "ft_printf.h"

static size_t		ft_digits(long double num)
{
	size_t i;
	long long	n;

	n = (int)num;
	i = 0;
	if (num == 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static size_t  dig_after_dot(long double *num)
{
    size_t  count;
	long long	n;
	long double	nb;

    count = 0;
	n = (int)(*num);
	nb = n;
    while (nb < *num)
    {
        *num *= 10;
		n = (int)(*num);
		nb = n;
        count++;
    }
	return (count);
}

char	*ft_fitoa(long double num)
{
	char        *str;
	long double nb;
	size_t      i;
	size_t		tmp;
	size_t		dig;
	long long	n;

	nb = num;
	if (num < 0)
		nb *= -1;
    dig = dig_after_dot(&nb);
	n = (int)nb;
	i = ft_digits(nb) + 1;
	tmp = i;
	if (num < 0)
		i++;
	if(!(str = ft_strnew(i)))
		return (NULL);
	while(i-- > 0)
	{
		if (num < 0 && i == 0)
			str[i] = '-';
		else if (i < tmp - dig)
		{
			str[i] = '.';
			i--;
		}
		str[i] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
