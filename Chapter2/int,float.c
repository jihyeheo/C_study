#include <stdio.h>	// stdio : standard input output�� ���Ӹ�

int main(void)
{
	printf("%d\n", 10);
	printf(" % lf\n", 3.14);
	printf(" % .1lf\n", 3.14);
	printf(" % .10lf\n", 3.14);



	printf("%d�� %d�� ���� %d�̴�. \n", 10, 20, 10 + 20);
	printf("%.1lf�� %1lf�� ���� %.lf�̴�.", 3.4, 1.2, 3.4-1.2);
	

	return 0;
}

