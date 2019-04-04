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
    char        type;
    int         precision;
    int         width;
    char        *size;
    char        flags[5];
}               t_spec;


int	    ft_printf(const char *format, ...);
void	print_and_smth(const char *format, va_list *ap);
int	    exeption(char const *format);
void	process_specifier(char *format, va_list *ap);
char    *type_specifier(t_spec *spec, va_list *ap); // функция возвращает указатель на char. Это значит, что надо выделить память mallocом!
void    width_specifier(char *res, t_spec *spec);
char    *precise_specifier(char *res, t_spec *spec);
void    flag_specifier(char *res, t_spec *spec, int flag);
void    print_param(char *res);
char    *s_precise(char *c, char *res, t_spec *spec);
char    *f_precise(char *c, char *res, t_spec *spec);
char    *other_precise(char *c, char *res, t_spec *spec);
void    call_specifier(va_list *ap, t_spec *spec, int flag);
char    *type_ouxX(char *res, t_spec *spec, va_list *ap);
char    *type_ouxX(char *res, t_spec *spec, va_list *ap);
char    *type_s(char *res, va_list *ap);
char	*type_p(char *res, va_list *ap);
char	*type_f(char *res, va_list *ap);
char    *type_id(char *res, va_list *ap);
char	*zero_flag(char *res);
char	*minus_flag(char *res);
char	*plus_flag(char *res);
char	*hash_flag(char *res);
char	*space_flag(char *res, t_spec *spec);

#endif
