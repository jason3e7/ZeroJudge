 /*
  * @file d904.c
  * @author Jason3e7
  * @algorithm DP
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
	int c, n, i, j, out[1001], coin[11];
	out[0] = 0;
	while(scanf("%d %d", &c, &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &coin[i]);
		}
		qsort(coin, n, sizeof(int), cmpfunc);
		for(i = 1; i < 1001; i++) {
			out[i] = 10000;
		}
		for(i = 0; i < n; i++) {
			for(j = coin[i]; j <= c; j++) {
				if(out[j - coin[i]] + 1 < out[j]) {
					out[j] = out[j - coin[i]] + 1;
				}
			}
		}
		printf("%d\n", out[c]);
		
	}
	return 0;
}



