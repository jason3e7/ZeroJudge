 /*
  * @file d280.c
  * @author Jason3e7
  * @algorithm math, DP
  * @date 201711111055
  * @note very hate no description about "parameter boundary problem"
  */

#include <stdio.h>

unsigned long long int r[21][121] = {0};

unsigned long long int getComb(int n, int m) {
	if(r[n][m] != -1) {
		return r[n][m];
	}
	if(m > n * 6 || n * 1 > m) {
		r[n][m]	= 0;
		return 0;
	}
	if(n == 1) {
		r[n][m] = 1;
		return 1;
	}
	int i;
	unsigned long long sum = 0;
	for(i = 1; i <= 6; i++) {
		sum += getComb(n - 1, m - i);
	}
	r[n][m] = sum;
	return sum;
}

int main() {
	int i, j;
	for(i = 0; i < 21; i++) {
		for(j = 0; j < 121; j++) {
			r[i][j] = -1;
		}
	}
	int k, n, m;
	while(scanf("%d", &k) != EOF) {
		while(k--) {
			scanf("%d %d", &n, &m);
			if(n <= 0 || n > 20 || n > m || m * 6 < n) {
				break;
			}
			printf("%llu\n", getComb(n, m));
		}			
	}
	return 0;
}
