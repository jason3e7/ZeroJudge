/*
 * @file d389.c
 * @author Jason3e7
 * @algorithm dynamicProgramming
 * @date 201512201458
 */

#include <stdio.h>

int main() {
	int i, dp[77], n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	for (i = 4; i < 77; i++) 
		dp[i] = dp[i - 2] + dp[i - 3];
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", dp[n]);
	}
	return 0;
}

