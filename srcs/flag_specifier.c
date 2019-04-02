#include "ft_printf.h"
char	*flag_specifier(char *res, t_spec *spec, int flag)
{
	if (spec->flags[flag] == '0')
		res = zero_flag(res);
	if (spec->flags[flag] == '-')
		res = minus_flag(res);
	if (spec->flags[flag] == '+')
		res = plus_flag(res);
	if (spec->flags[flag] == '#')
		res = hash_flag(res);
	res = space_flag(res);
	return (res);
}

char	*zero_flag(char *res)
{

}

char	*minus_flag(char *res)
{

}

char	*plus_flag(char *res)
{

}

char	*hash_flag(char *res)
{

}

char	*space_flag(char *res)
{

}
