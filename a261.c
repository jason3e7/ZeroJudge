/*
 * @file a261.c
 * @author Jason3e7
 * @algorithm dynamicProgramming
 * @date 201512261920
 */

#include <stdio.h>
#define MAX 64

int main() {
	int i, j, k, flag;
	unsigned long long int n, map[MAX][MAX] = {0};
	map[1][1] = 1;
	for (i = 1; i < MAX; i++) 
		for (j = 1; j < MAX; j++) 
			map[i][j] = map[i - 1][j - 1] + 1 + map[i][j - 1];
	
	while (scanf("%d %lld", &k, &n) != EOF) {
		if (k == 0)
			break;
		flag = 0;
		if (k >= MAX)
			k = MAX - 1;
		for (i = 1; i < MAX; i++) {
			if (map[k][i] >= n) {
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
