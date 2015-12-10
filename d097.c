/*
 * @file d097.c
 * @author Jason3e7
 * @algorithm controlFlow
 * @date 201512101553
 */

#include <stdio.h>

int abs(int n) {
	if (n >= 0)
		return n;
	return (n * -1);
}

int main() {
	int i, n, num[3001], flag[3001], out;
	while(scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &num[i]);
			flag[i] = 0;
		}
		out = 1;
		for (i = 1; i < n; i++) 
			flag[abs(num[i] - num[i - 1])]++;
		
		for (i = 1; i < n; i++) {
			if (flag[i] != 1) {
				out = 0;
				break;
			}
		}
		if (out == 1)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}

