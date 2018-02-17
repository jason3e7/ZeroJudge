 /*
  * @file b540.c
  * @author Jason3e7
  * @algorithm math
  * @date 201802150920
  * @note equiangular hexagon properties
  * any not adjoin three line can fill to equilateral triangle
  * 4 types? no !?
  * 1 1 1 1 1 1
  * 1 2 1 2 1 2
  * 1 2 3 1 2 3
  * 1 3 2 2 2 3
  *
  * 1 5 3 4 2 6
  * 
  * getTriangleCount => (1 + (n * 2 - 1)) * n / 2
  */

#include <stdio.h>

int main() {
	int a[6], temp;
	while(scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) != EOF) {
		temp = a[0] + a[1] + a[2];
		printf("%d\n", temp * temp - a[0] * a[0] - a[2] * a[2] - a[4] * a[4]);
	}
	return 0;
}
