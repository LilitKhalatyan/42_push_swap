#include "push_swap.h"
//1
int	ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
//2
int		ft_find_duplicates(int *array, int num, int c) // ?* **
{
	int i;

	i = 0;
	while (i < c)
	{
		if(array[i] == num)
			return (1);
		i++;
	}
	return(0);
}
//3
long	ft_atoi(char *str)
{
	int i;
	long num;
	int sign;

	sign = 1;
	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		num = num * sign;
	}
	return(num);
}

void ft_bubble_sort(int *array, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j+1])
			{
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void ft_sort_array(int *array_1, int len)
	{
		int *array_2;
		int i;
		int j;
		int tmp;

		array_2 = malloc(sizeof(int) * len);
		i = 0;
		while (i < len)
		{
			array_2[i] = array_1[i];
			i++;
		}
		i = 0;
		ft_bubble_sort(array_2, len);
		while (i < len)
		{
			j = 0;
			while (j < len)
			{
				if (array_1[i] == array_2[j])
					array_1[i] = j;
				j++;
			}
			i++;
		}
	}

int		*ft_check_errors(stack *stack_a, int argc, char **argv) // 4
{
	int	i;
	char **array;
	int *array_1;
	int len;

	i = 0;
	len = 0;
	if (argc == 1)
		return(0);
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		while (array[len] != NULL)
		{
			if (ft_str_is_numeric(array[len]) == 0 || ft_atoi(array[len]) < -2147483648 || ft_atoi(array[len]) > 2147483647)
				return(0);
			len++;
		}
	}
	else
	{
		array = malloc(sizeof(char*) * (argc - 1));
		if (!array)
			return (0);
		len = 1;
		while (len < argc)
		{
			if (ft_str_is_numeric(argv[len]) == 0 || ft_atoi(argv[len]) < -2147483648 || ft_atoi(argv[len]) > 2147483647)
				return(0);		
			array[len - 1] = argv[len];
			len++;
		}
		len--;
	}
	i = 0;
	array_1 = malloc(sizeof(int) * len);
	while (i < len)
	{
		array_1[i] = ft_atoi(array[i]);
		if (ft_find_duplicates(array_1, array_1[i], i))
		{
			free(array_1);
			return(0);
		}
		i++;
	}
	ft_sort_array(array_1, len);
	// i = 0;
	// while (i < len)
	// {
	// 	printf("%d\n", array_1[i]);
	// 	i++;
	// }
	while (--len >= 0)
		ft_push(stack_a, array_1[len]);
	return(array_1);
}
