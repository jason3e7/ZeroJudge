/*
 * @file d580.c
 * @author Jason3e7
 * @date 201510051517
 */

#include <stdio.h>

int main() {
	int t, n, number[101][101], i, j, k, m;
	i = 50;
	j = 50;
	number[i][j] = 1;
	for (k = 1; k <= 98; k++) {
		if (k % 2 ==1) {
			for (m = k; m > 0; m--) {
				number[i][j + 1] = number[i][j] + 1;
				j++;
			}
			for (m = k; m > 0; m--) {
				number[i - 1][j] = number[i][j] + 1;
				i--;
			}
		} else {
			for (m = k; m > 0; m--) {
				number[i][j - 1] = number[i][j] + 1;
				j--;
			}
			for (m = k; m > 0; m--) {
				number[i + 1][j] = number[i][j] + 1;
				i++;
			}
		}
	}
	for (k = 1; k <= 98; k++) {
		number[i][j + 1] = number[i][j] + 1;
		j++;
	}
	while(scanf("%d", &t) != EOF) {
		while (t--) {
			int begin, end;
			scanf("%d", &n);
			n = n / 2;
			begin = 50 - n;
			end = 50 + n;
			for (i = begin; i <= end; i++) {
				for (j = begin; j <= end; j++) {
					if (j == end) 
						printf("%4d\n", number[i][j]);
					else
						printf("%4d ", number[i][j]);
				}
			}
		}
	}
	return 0;
}

//printf("%d %d %4d\n", i, j, number[i][j]);
