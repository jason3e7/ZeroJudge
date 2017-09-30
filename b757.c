 /*
  * @file b757.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710011144
  */

#include <stdio.h>
int main() {
	double r;
	while(scanf("%lf", &r) != EOF) {
		printf("%lg\n", (r * 9 / 5) + 32);
	}
	return 0;
}

