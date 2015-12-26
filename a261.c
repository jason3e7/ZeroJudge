/*
 * @file a261.c
 * @author Jason3e7
 * @algorithm dynamicProgramming
 * @date 201512261920
 */

#include <stdio.h>

unsigned long long int map[63][63] = {0};

unsigned long long int getMaxLevel(int b, int t) {
	if (b >= t)
		return map[t][t];
	if (b == 2)
		return map[2][t];
	map[b][t] = getMaxLevel(b - 1, t - 1) + 1 + getMaxLevel(b, t - 1);
	return map[b][t];
}

int main() {
	int i, k, flag;
	unsigned long long int n;
	map[1][1] = 1;
	map[2][2] = 3;
	for (i = 2; i < 64; i++) 
		map[1][i] = i;
	for (i = 3; i < 64; i++) 
		map[2][i] = map[2][i - 1] + i;
	for (i = 3; i < 64; i++) 
		map[i][i] = (map[i - 1][i - 1] * 2) + 1;
	while (scanf("%d %lld", &k, &n) != EOF) {
		if (n == 0 && k == 0)
			break;
		flag = 0;
		for (i = 1; i < 64; i++) {
			if (getMaxLevel(k, i) >= n) {
				printf("%d\n", i);
				flag = 1;
				break;
			}
		}
		if (flag == 0) 
			printf("More than 63 trials needed.\n");
	}
	return 0;
}
