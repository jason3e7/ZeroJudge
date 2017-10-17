 /*
  * @file d904.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710180929
  * @test case
10 3
1
5
6
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
	int c, n, i, coin[1001], out;
	while(scanf("%d %d", &c, &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &coin[i]);
		}
		qsort(coin, n, sizeof(int), cmpfunc);
		out = 0;
		for(i = n - 1; i >= 0; i--) {
			out += (c / coin[i]);
			c = c % coin[i];
		}
		printf("%d\n", out);
	}
	return 0;
}



