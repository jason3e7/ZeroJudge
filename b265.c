 /*
  * @file b265.c
  * @author Jason3e7
  * @algorithm array
  * @UVa 11286
  * @date 201710162117
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

int arrayCompare(int a[], int b[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}

int arrayCopy(int a[], int b[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		a[i] = b[i];
	}
	return 0;
}

int main() {
	int n, i, j, class[10001][5], count[10001], point, temp[5], flag, max;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		for(i = 0; i < 10001; i++) {
			count[i] = 0;
		}
		point = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);
			qsort(temp, 5, sizeof(int), cmpfunc);
			flag = 1;
			for(j = 0; j < point; j++) {
				if(arrayCompare(temp, class[j], 5) == 1) {
					count[j]++;
					flag = 0;
					break;
				}
			}
			if(flag == 1) {
				arrayCopy(class[point], temp, 5);
				count[point]++;
				point++;
			}
		}
		max = 0;
		flag = 0;
		for(i = 0; i < point; i++) {
			if(count[i] > max) {
				max = count[i];
				flag = 1;
			} else if(count[i] == max) {
				flag++;
			}
		}
		printf("%d\n", flag * max);
	}
	return 0;
}



