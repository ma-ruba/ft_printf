#ifndef FT_PRINTF_H
# define FT_PRINT_F

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int     ret;
int     i;

typedef struct  s_type
{
    char        ch;
}               t_type;


int	    ft_printf(const char *format, ...);
void	print_and_smth(const char *format, va_list *ap);
int	    exeption(char const *format);
void	process_specifier(char *format, va_list *ap);
char    *type_specifier(char c, va_list *ap, t_type *type); // функция возвращает указатель на char. Это значит, что надо выделить память mallocом! А еще надо заполнить структуру t_type
void    size_specifier(char *c, char *res);
void    width_specifier(char *c, char *res);
char    *precise_specifier(char *c, char *res, t_type *type);
void    flag_specifier(char c, char *res);
void    print_param(char *res);
char    *f_precise(char *c, char *res);
char    *s_precise(char *c, char *res);

#endif
