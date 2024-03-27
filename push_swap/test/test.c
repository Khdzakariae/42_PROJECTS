#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int size)
{
	int i = 1;
	while(i <= size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}
void _sort(int *values, int size)
{
	int i ;
	int tmp = 0;
	while(size)
	{
		i = 0;
		while(i < size)
		{
			if (values[i] > values[i + 1])  
			{
				tmp = values[i] ;
				values[i] = values[i + 1];
				values[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
}
int main (int ac , char **av)
{
	if (ac != 1)
	{
		int i = 0;
		int tmp = 0;
		int size = ac - 1;
		int *values = (int *)malloc(sizeof(int) * ac - 1);;

		while(i < ac -1)
		{
			tmp = atoi(av[i + 1]);
			values[i] = tmp;
			i++;
		}
		_sort(values, ac -1);
		print(values,size);	
	}
}