/*
 * @file d164.c
 * @author Jason3e7
 * @date 201510010012
 */

#include <stdio.h>

int main() {
	int n, m, i, cow[10001], sum[10001], max, j;
	while(scanf("%d %d", &n, &m) != EOF) {
		for (i = 0; i < n; i++) 
			scanf("%d", &cow[i]);
		for (i = 0; i < n; i++) {
			sum[i] = cow[i];
			for (j = i + 1; j < i + m; j++) {
				if (j >= n ) 
					sum[i] += cow[j - n];
				else
					sum[i] += cow[j];
			}
		}
		max = sum[0];
		for (i = 1; i < n; i++)
			if (sum[i] > max)
				max = sum[i];
		printf("%d\n", max);
	}
	return 0;
}
