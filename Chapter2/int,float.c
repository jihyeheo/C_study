#include <stdio.h>	// stdio : standard input output의 줄임말

int main(void)
{
	printf("%d\n", 10);
	printf(" % lf\n", 3.14);
	printf(" % .1lf\n", 3.14);
	printf(" % .10lf\n", 3.14);



	printf("%d와 %d의 합은 %d이다. \n", 10, 20, 10 + 20);
	printf("%.1lf와 %1lf의 차는 %.lf이다.", 3.4, 1.2, 3.4-1.2);
	

	return 0;
}

