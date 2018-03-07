 /*
  * @file b966.c
  * @author Jason3e7
  * @algorithm 2d sort
  * @date 201803081122
  * @note https://stackoverflow.com/questions/17202178/c-qsort-with-dynamic-n-by-2-multi-dimensional-array
  */

#include <stdio.h>
#include <stdlib.h>

int compare ( const void *pa, const void *pb ) {
	const int *a = *(const int **)pa;
	const int *b = *(const int **)pb;
    if(a[0] == b[0]) {
		return a[1] - b[1];
	} else {
		return a[0] - b[0];
	}
}

int main() {
	int n, i, a, b, sum;
	int **num;
	while(scanf("%d", &n) != EOF) {
    	if(n <= 0) {
			printf("0\n");
			continue;
		}
		num = malloc(n * sizeof(int*));
		for(i = 0; i < n; i++) {
			num[i] = malloc(2 * sizeof(int));
			scanf("%d %d", &num[i][0], &num[i][1]);
		}
		qsort(num, n, sizeof num[0], compare);
		a = 0;
		b = 0;
		sum = 0;
		for(i = 0; i < n; i++) {
			if(num[i][1] > b) {
				if(num[i][0] >= b) {
					a = num[i][0];
					b = num[i][1];
					sum += (b - a);
				} else {
					sum += (num[i][1] - b);
					b = num[i][1];
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
