 /*
  * @file d401.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201802181257
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main() {
	int n, a, b, x[1000000], y[1000000], xPoint, yPoint, out;
	while(scanf("%d", &n) != EOF) {
		xPoint = 0, yPoint = 0;
		while(n--) {
			scanf("%d %d", &a, &b);
			if(a == 1) {
				x[xPoint] = b;
				xPoint++;
			} else if (a == 2) {
				y[yPoint] = b;
				yPoint++;
			}
		}
		qsort(x, xPoint, sizeof(int), cmpfunc);
		qsort(y, yPoint, sizeof(int), cmpfunc);
		scanf("%d", &a);
		out = x[a - 1] - y[a - 1]; 
		if(out > 0)  {
			printf("1 %d\n", out);
		} else {
			printf("2 %d\n", out * -1);
		}
	}
	return 0;
}
