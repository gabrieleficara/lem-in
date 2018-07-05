/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:53:13 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 12:50:31 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>
# include <wchar.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 2000
# define MAX_FD 4864

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_ligne
{
	char			*array;
	char			*tab;
	char			*stock;
	int				i;
}					t_ligne;

typedef struct		s_p
{
	int						total;
	int						hh;
	int						h;
	int						l;
	int						ll;
	int						j;
	int						z;
	char					*word;
	char					*finale;
	int						choix;
	int						plus;
	int						plus2;
	int						espace;
	int						diese;
	int						point;
	int						nb;
	int						e;
	int						e2;
	int						l1;
	char					*array;
	wchar_t					arraywchar;
	char					caractere;
	unsigned long long int	nombre;
	long long int			nombre2;
	long int				nombre3;
	void					*nombrep;
}					t_p;

char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_printf(const char *str, ...);
void				apel(char c, t_p *p);
void				appel_caractere(t_p *p);
void				appel_pourcentage(t_p *p);
void				pointeur(void const *c, t_p *p);
void				conversion_u(t_p *p, char u);
int					conversion_binaire2(int c);
void				conversion_octet(t_p *p, char o);
void				conversion_big_x(t_p *p);
void				conversion_mini_x(t_p *p);
int					width_int(char c, unsigned int nombre);
void				ecrire(char c, t_p *p);
void				decimal(unsigned int nb, t_p *p);
void				conversion_grand_s(va_list *va, t_p *p);
void				conversion_p(void const *c, t_p *p);
int					ft_printf(const char *str, ...);
void				ft_putnbra(long long int nombre, t_p *p, char c);
void				ft_putstra(char *str, t_p *p);
void				ft_strdel(char **as);
int					ft_strchrtab(const char *s, const char *s2);
size_t				ft_strlen(const char *s);
void				ft_putchar(int c, t_p *p);
void				ft_putstr(char const *s, t_p *p);
void				ft_putnbr(long long int n, t_p *p);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
int					width_int(char c, unsigned int nombre);
void				mettre_zero(int nombre, t_p *p);
void				plus(int nombre, char *nb, t_p *p);
void				ft_putespace(t_p *p);
void				justify(t_p *p);
void				diese(char c, t_p *p);
void				specifier(char const *str, int *j, t_p *p, va_list *va);
void				abuser(const char *str, int *j, t_p *p);
void				find_flag(const char *str, int *j, t_p *p);
void				find_other_flag(char const *str, int *j, t_p *p);
void				return_int(va_list *va, t_p *p);
void				return_unsigned_int(va_list *va, t_p *p);
void				return_long_int(va_list *va, t_p *p);
int					binaire(int i);
void				conversion_binaire(wint_t wint, t_p *p);
char				*ft_sfstrjoin(char const *s1, char const *s2, int c);
int					get_next_line(int const fd, char **line);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *meule_de_foin, const char *aiguille);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *nptr);

#endif
