 /*
  * @file qsort.c
  * @author Jason3e7
  * @algorithm sort
  * @date 201710121245
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
	int n, m[100001], i;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &m[i]);
		}
		qsort(m, n, sizeof(int), cmpfunc);
		for(i = 0; i < n - 1; i++) {
			printf("%d ", m[i]);
		}
		printf("%d\n", m[n - 1]);	
	}
	return 0;
}

