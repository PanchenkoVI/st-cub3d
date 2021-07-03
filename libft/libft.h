/*
* Created: 2020/10/27 17:21:07
*/

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_isdigit(int n);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *str, int ch);
size_t				ft_strlen(const char *str);
void				ft_putstr(const char *s);
void				*ft_calloc(size_t str, size_t size);
void				ft_bzero(void *str, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *dest, int c, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);

#endif
