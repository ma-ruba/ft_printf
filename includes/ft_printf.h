#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int     ret;
int     i;
int     zero;

typedef struct  s_spec
{
    char        type;
    int         precision;
    int         width;
    char        size[2];
    char        flags[5];
}               t_spec;


int	    ft_printf(const char *format, ...);
void	print_and_smth(const char *format, va_list *ap);
void	process_specifier(char *format, va_list *ap);
char    *type_specifier(t_spec *spec, va_list *ap);
char    *width_specifier(char *res, t_spec *spec);
char    *precise_specifier(char *res, t_spec *spec);
char    *flag_specifier(char *res, t_spec *spec, int flag);
void    print_param(char *res);
char    *s_precise(char *res, t_spec *spec);
char    *f_precise(char *res, t_spec *spec);
char	*type_percent(char *res);
char    *other_precise(char *res, t_spec *spec);
void    call_specifier(va_list *ap, t_spec *spec, int flag);
char    *type_ouxX(char *res, t_spec *spec, va_list *ap);
char    *type_s(char *res, va_list *ap);
char	*type_p(char *res, va_list *ap, t_spec *spec);
char	*type_f(char *res, va_list *ap, t_spec *spec);
char	*type_c(char *res, va_list *ap);
char    *type_id(char *res, va_list *ap, t_spec *spec);
char	*zero_flag(char *res, t_spec *spec);
char	*minus_flag(char *res, t_spec *spec);
char	*plus_flag(char *res, t_spec *spec);
char	*hash_flag(char *res, t_spec *spec);
char	*space_flag(char *res, t_spec *spec);
char	*ft_fitoa(long double num);
char	*ft_itoa_base(long long num, int base, t_spec  *spec);
char	*ft_itoa_neg_base(char *str, t_spec *spec, int base);
void	find_width_param(char *format, va_list *ap, t_spec *spec);

#endif
