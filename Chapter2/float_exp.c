#include <stdio.h>

int main(void)
{
	printf("%.lf\n", 1e6);
	printf("%.4lf\n", 3.15e-4);
	printf("%le\n", 0.000000015);
	printf("%.2le\n", 0.0000314);

	return 0;
}