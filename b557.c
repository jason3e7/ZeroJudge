 /*
  * @file b557.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710191619
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
	int t, n, i, j, k, number[101], out;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d", &n);
			for(i = 0;i < n; i++) {
				scanf("%d", &number[i]);
			}
			qsort(number, n, sizeof(int), cmpfunc);
			out = 0;
			for(i = 0;i < n; i++) {
				for(j = i + 1;j < n; j++) {
					for(k = j + 1;k < n; k++) {
						if((number[i] + number[j]) > number[k]) {
							if((number[i] * number[i] + number[j] * number[j]) == (number[k] * number[k])) {
								out++;
							}
						}
					}
				}
			}
			printf("%d\n", out);
		}
	}
	return 0;
}

