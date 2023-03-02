#include "libft.h"

t_doubly	*ft_create_node(void *content, size_t size)
{
	t_doubly	*new;

	new = malloc(sizeof(t_doubly));
	if (!new)
		return (NULL);
	if (content)
	{
		new->obj = content;
		new->size = size;
	}
	else
	{
		new->obj = NULL;
		new->size = 0;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
