#include <stdlib.h>
#include "include/struct.h"
#include "include/put_other_list.h"
#include "include/swap.h"

void   	switch_node(t_list *l_a, t_list *l_b, int cpt)
{
  int	i;

  i = 1;
  while (i < cpt)
    {
      pb(l_a, l_b);
      i++;
      my_putchar(' ');
    }
  i = 1;
  sa(l_a);
  my_putchar(' ');
  while (i < cpt)
    {
      pa(l_a, l_b);
      my_putchar(' ');
      i++;
    }
}

int		sort_list(t_list *l_a, t_list *l_b)
{
  t_node	*tmp;
  int		i;
  int		no_switch;
  
  while (1)
    {
      i = 1;
      no_switch = 1;
      while (tmp != NULL)
	{
	  if (tmp->next != NULL && tmp->value > tmp->next->value)
	    {
	      no_switch = 0;
	      switch_node(l_a, l_b, i);
	    }
	  if (tmp == l_a->last && no_switch == 1)
	    return (1);
	  else
	    {
	      tmp = tmp->next;
	      i++;
	    }
	}
      tmp = l_a->first;
    }
}
