 /*
  * @file a737.c
  * @author Jason3e7
  * @algorithm sort
  * @UVa 10041
  * @date 201710181145
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
	int n, r, i, location[30001], out, point;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%d", &r);
			for(i = 0; i < r; i++) {
				scanf("%d", &location[i]);
			}
			qsort(location, r, sizeof(int), cmpfunc);
			out = 0;
			point = r / 2;
			for(i = 0; i < r; i++) {
				out += abs(location[i] - location[point]);
			}
			printf("%d\n", out);
		}
	}
	return 0;
}

