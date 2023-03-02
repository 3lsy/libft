#include "libft.h"

void	ft_insert_first(void *content, t_size size, t_doubly **start, t_doubly *end)
{
	t_doubly	*new;

	new = ft_create_node(content, size);
	if (!(*start))
	{
		new->next = new;
		new->prev = new;
		*start = new;
		return ;
	}
	end->next = new;
	new->next = *start;
	new->prev = end;
	(*start)->prev = new;
	*start = new;
}
