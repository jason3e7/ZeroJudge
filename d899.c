 /*
  * @file d899.c
  * @author Jason3e7
  * @algorithm DP
  * @date 201801030941
  */

#include <stdio.h>

int main() {
	int temp[5] = {0, 0, 0, 0, 0};
	int sum[10001], i, j;
	sum[0] = 0;
	sum[1] = 0;
	temp[0] = 2;
	for(i = 2; i < 10001; i++) {
		sum[i] = sum[i - 1];
		for(j = 0; j < 5 ; j++) {
			if(temp[j] == 2) {
				sum[i]++;
			}
		}

		temp[0]++;
		for(j = 0; j <= 3 ; j++) {
			if(temp[j] >= 10) {
				temp[j + 1]++;
				temp[j] = 0;
			}
		}
	}
	int l, r;
	while(scanf("%d %d", &l, &r) != EOF) {
		printf("%d\n", sum[r] - sum[l - 1]);
	}
	return 0;
}

