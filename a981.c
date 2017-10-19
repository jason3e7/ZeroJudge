 /*
  * @file a981.c
  * @author Jason3e7
  * @algorithm brute force
  * @date 201710201131
  */

#include <stdio.h>
#include <stdlib.h>

int n = 0, m = 0, number[31] = {0}, out[31] = {0}, flag = 0;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int printSum(int count, int cPoint, int oPoint) {
	int i;
	if(count > m) {
		return 0;
	} else if(count == m) {
		for(i = 0; i < oPoint; i++) {
			if(i == 0) {
				printf("%d", out[i]);
			} else {
				printf(" %d", out[i]);
			}
		}
		printf("\n");
		flag = 1;
		return 0;
	} else if(count < m) {
		for(i = cPoint; i < n; i++) {
			out[oPoint] = number[i];
			printSum(count + number[i], i + 1, oPoint + 1);
		}
	}
	return 0;
}

int main() {
	int i;
	while(scanf("%d %d", &n, &m) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &number[i]);
		}
		flag = 0;
		qsort(number, n, sizeof(int), cmpfunc);
		printSum(0, 0, 0);
		if(flag == 0) {
			printf("-1\n");
		}
	}
	return 0;
}

