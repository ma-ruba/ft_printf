#ifndef FT_PRINTF_H
# define FT_PRINT_F

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int	    ft_printf(const char *format, ...);
void	print_and_smth(const char *format, va_list *ap, int *ret);
int	    exeption(char const *format);
void	process_specifier(const char *format, int *ret, int *i);
void    type_specifier(char c, );
void    size_specifier(char *c, );
void    width_specifier();

#endif
