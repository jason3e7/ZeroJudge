 /*
  * @file doubleaccuracy.c
  * @author Jason3e7
  * @algorithm accuracy
  * @date 201710201111
  */

#include <stdio.h>
const double capaity = 1e-6;

int main() {
	double n;
	printf("%.2lf\n",329.155);
	printf("%.2lf\n",329.985);
	printf("%.2lf\n",329.155 + capaity);
	printf("%.2lf\n",329.985 + capaity);
	while(scanf("%lf", &n) != EOF) {
		printf("%.2lf\n", n);
		if(n >= 0) {
			printf("%.2lf\n ", n + capaity);
		} else {
			printf("%.2lf\n ", n - capaity);
		}
	}
	return 0;
}

