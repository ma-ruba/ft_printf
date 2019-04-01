#ifndef FT_PRINTF_H
# define FT_PRINT_F

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int     ret;
int     i;

int	    ft_printf(const char *format, ...);
void	print_and_smth(const char *format, va_list *ap);
int	    exeption(char const *format);
void	process_specifier(char *format, va_list *ap);
char    *type_specifier(char c, va_list *ap); // функция возвращает указатель на char. Это значит, что надо выделить память mallocом!
void    size_specifier(char *c, char *res);
void    width_specifier(char *c, char *res);
void    precise_specifier(char *c, char *res);
void    flag_specifier(char c, char *res);
void    print_param(char *res);

#endif

// Мне надо потом освободить память, которую выделит Милла!