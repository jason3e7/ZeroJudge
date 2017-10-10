 /*
  * @file c278.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710111023
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
	int n, m[100001], i, j, out, swap;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &m[i]);
		}
		qsort(m, n, sizeof(int), cmpfunc);
		out = 0;
		for(i = 0; i < n; i+=2) {
			out += (m[i + 1] - m[i]);
		}
		printf("%d\n", out);
		
	}
	return 0;
}

