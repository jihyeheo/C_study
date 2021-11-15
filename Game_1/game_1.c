# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arrnum(int* ptr)
{
	int i;
	for (i = 0;i < 5;i++)
	{
		printf("%d", *(ptr + i));
	}
}

int main(void)
{
	int i, re = 1;
	int save, input;
	int arr[5];
	while (re == 1)
	{
		int arr[5] = {4,5,1,3,2};
		re = 0;
		printf("|1|2|3|4|\n");
		arrnum(arr);
		for (i = 10; i > 0; i--)
		{
			save = 0;
			do
			{
				printf("\n@@1~4 input:@@");
				scanf("%d", &input);
			} while (input > 5 || input < 0);

			save = arr[input - 1];
			arr[input - 1] = arr[input];
			arr[input] = save;

			arrnum(arr);
if ((arr[0] == 1 && arr[1] == 2) && (arr[2] == 3 && arr[3] == 4) && (arr[4] == 5))
			{
			printf("\n You Win!");
			printf("\nYou cleaned in %d times!\n", 10 - i);
			break;


			}
		}
		if (i == 0)
		{
			printf("\Your lose\n");
			scanf("%d", &re);
		}
	}
	return 0;
}