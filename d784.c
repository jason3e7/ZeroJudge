 /*
  * @file d784.c
  * @author Jason3e7
  * @algorithm DP
  * @date 201712291032
  */

#include <stdio.h>

int main() {
	int t, n, i, row[100], sum, max;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d", &n);
			max = -10001;
			for(i = 0; i < n; i++) {
				scanf("%d", &row[i]);
				if(row[i] > max) {
					max = row[i];
				}
			}
			sum = 0;
			for(i = 0; i < n; i++) {
				sum += row[i];
				if(sum > max) {
					max = sum;
				}
				if(sum < 0) {
					sum = 0;
				}
			}
			printf("%d\n", max);
		}
	}
	return 0;
}
