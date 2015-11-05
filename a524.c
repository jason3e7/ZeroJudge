/*
 * @file a524.c
 * @author Jason3e7
 * @date 201511051018
 */

#include <stdio.h>

int num[9], n, out[8];

void printPW(int len) {
	int j;
	if (len == n) {
		for (j = 0; j < n; j++) 
			printf("%d", out[j]);
		printf("\n");
		return;
	}
	for (j = n; j >= 1; j--) {
		if (num[j] == 0) {
			num[j] = 1;
			out[len] = j;
			printPW(len + 1);
			num[j] = 0;
		}
	}
}

int main() {
	int i;
	while(scanf("%d", &n) != EOF) {
		for (i = 1; i <= 8; i++) 
			num[i] = 0;
		printPW(0);
	}
	return 0;
}
