#ifndef FT_PRINTF_H
# define FT_PRINT_F

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int     ret;
int     i;

typedef struct  s_spec
{
    char        ch;
    int         precision;
    int         width;
    char        flags[5];
}               t_spec;


int	    ft_printf(const char *format, ...);
void	print_and_smth(const char *format, va_list *ap);
int	    exeption(char const *format);
void	process_specifier(char *format, va_list *ap);
char    *type_specifier(char c, va_list *ap, t_spec *spec); // функция возвращает указатель на char. Это значит, что надо выделить память mallocом! А еще надо заполнить структуру t_type
void    size_specifier(char *c, char *res);
void    width_specifier(char *c, char *res, t_spec *spec);
char    *precise_specifier(char *c, char *res, t_spec *spec);
void    flag_specifier(char c, char *res, t_spec *spec, int *count_flag);
void    print_param(char *res);
char    *s_precise(char *c, char *res, t_spec *spec);
char    *f_precise(char *c, char *res, t_spec *spec);
char    *other_precise(char *c, char *res, t_spec *spec);

#endif
