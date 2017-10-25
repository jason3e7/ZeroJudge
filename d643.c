 /*
  * @file d643.c
  * @author Jason3e7
  * @algorithm DP(0/1 Knapsack Problem)
  * @date 201710261019
  */

#include <stdio.h>

int n, v[10001], s[10001], dp[10001][100];

int max(int a, int b) {
	if(a > b) {
		return a;
	}
	return b;
}

int findMax(int point, int existV) {
	if(existV < 0) {
		return -1e9;
	}
	if(point == 0) {
		return 0;
	}
	if(dp[point][existV] == 0) {
		dp[point][existV] = max(findMax(point - 1, existV), findMax(point - 1, existV - v[point]) + s[point]);
	}
	return dp[point][existV];
}

int main() {
	int i, n, j;
	while(scanf("%d", &n) != EOF) {
		for(i = 1; i <= n; i++) {
			scanf("%d %d", &v[i], &s[i]);
		}
		for(i = 0; i < 10001; i++) {
			for(j = 0; j < 101; j++) {
				dp[i][j] = 0;
			}
		}
		printf("%d\n", findMax(n, 100));
	}
	return 0;
}

