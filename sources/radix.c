#include <push_swap.h>

int	binary_check(int data, int bit)
{
	if (!data)
		return (0);
	data >>= bit;
	if (data & 1)
		return (1);
	else
		return (0);
}

void	radix(t_list **stack_a, t_list **stack_b, t_values *main)
{
	int	len;
	int	bit;
	int	i;
	int	j;

	len = ft_lstsize(*stack_a);
	mapping(stack_a);
	if (check_sort(stack_a, main) == 1)
		return ;
	bit = 0;
	while ((len - 1) >> bit != 0)
		bit++;
	i = 0;
	while (i < bit)
	{
		j = 0;
		while (j < len)
		{
			if (check_sort(stack_a, main) == 1) //si si está ordenado
				break ;
			if (((stack_a[0]->index >> i) & 1) == 1) //  >> takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift
				ft_rotate(stack_a, 0);
			else
				do_push(stack_a, stack_b, main, 0);
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			do_push(stack_a, stack_b, main, 1);
		i++;
	}
}