/*
* Created: 2020/10/27 17:21:07
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *past;

	past = lst;
	if (lst != 0)
	{
		while (past->next)
			past = past->next;
	}
	return (past);
}
