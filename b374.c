 /*
  * @file b374.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710041022
  */

#include <stdio.h>
int main() {
	int n, m, sum[30001], i, max;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < 30001; i++) {
			sum[i] = 0;
		}
		max = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &m);
			sum[m]++;
			if (sum[m] > max) {
				max = sum[m];
			}
		}
		for(i = 0; i < 30001; i++) {
			if (sum[i] == max) {
				printf("%d %d\n", i, max);
			}
		}
	}
	return 0;
}

