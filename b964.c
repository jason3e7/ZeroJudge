 /*
  * @file b964.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710171051
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

int main() {
	int n, i, student[21], max, min;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &student[i]);
		}
		qsort(student, n, sizeof(int), cmpfunc);
		max = -1;
		min = 101;
		for(i = 0; i < n; i++) {
			if(max < student[i] && student[i] < 60) {
				max = student[i];
			}
			if(student[i] >= 60) {
				break;
			}
		}
		for(i = n - 1; i >= 0; i--) {
			if(min > student[i] && student[i] >= 60) {
				min = student[i];
			}
			if(student[i] < 60) {
				break;
			}
		}
		for(i = 0; i < n - 1; i++) {
			printf("%d ", student[i]);
		}
		printf("%d\n", student[n - 1]);
		if(max == -1) {
			printf("best case\n");
		} else {
			printf("%d\n", max);
		}
		if(min == 101) {
			printf("worst case\n");
		} else {
			printf("%d\n", min);
		}
	}
	return 0;
}



