 /*
  * @file d280.c
  * @author Jason3e7
  * @algorithm math, DP
  * @date 201711111055
  */

#include <stdio.h>

int r[21][121] = {0};

int getComb(int n, int m) {
	if(m > n * 6 || n * 1 > m) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	if(r[n][m] != -1) {
		return r[n][m];
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
			printf("%d\n", getComb(n, m));
		}			
	}
	return 0;
}

