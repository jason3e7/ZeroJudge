 /*
  * @file c469.c
  * @author Jason3e7
  * @algorithm math
  * @date 201802131411
  */

#include <stdio.h>
#include <math.h>

int main() {
	int n, temp;
	while(scanf("%d", &n) != EOF) {
		temp = (int)sqrt(n);
		printf("%d\n", n - (temp * temp));
	}
	return 0;
}
