/*
 * @file d045.c
 * @author Jason3e7
 * @date 201605252246
 */

#include <stdio.h>

int main() {
	int t, count = 1;
	while(scanf("%d", &t) != EOF) {
		while (t--) {
			int i, j, temp, sum[3], number[3][10001] = {0};
			for (i = 0; i < 3; i++) {
				scanf("%d", &sum[i]);
				for (j = 0; j < sum[i]; j++) {
					scanf("%d", &temp);
					number[i][temp]++;
				}
			}
			for (i = 1; i < 10001; i++) {
				if (number[0][i] > 0) {
					if (number[1][i] > 0) {
						number[0][i] = 0;
						number[1][i] = 0;
						sum[0]--;
						sum[1]--;
						if (number[2][i] > 0) {
							number[2][i] = 0;
							sum[2]--;
						}
					}
					if (number[2][i] > 0) {
						number[0][i] = 0;
						number[2][i] = 0;
						sum[0]--;
						sum[2]--;
					}
				}
				if (number[1][i] > 0 && number[2][i] > 0) {
					number[1][i] = 0;
					number[2][i] = 0;
					sum[1]--;
					sum[2]--;
				}
			}
			printf("Case #%d:\n", count);
			if (sum[0] >= sum[1] && sum[0] >= sum[2]) {
				printf("%d %d", 1, sum[0]);
				for (i = 1; i < 10001; i++) 
					if (number[0][i] > 0)
						printf(" %d", i);
				printf("\n");
			}
			if (sum[1] >= sum[0] && sum[1] >= sum[2]) {
				printf("%d %d", 2, sum[1]);
				for (i = 1; i < 10001; i++) 
					if (number[1][i] > 0)
						printf(" %d", i);
				printf("\n");
			}
			if (sum[2] >= sum[0] && sum[2] >= sum[1]) {
				printf("%d %d", 3, sum[2]);
				for (i = 1; i < 10001; i++) 
					if (number[2][i] > 0)
						printf(" %d", i);
				printf("\n");
			}
			count++;
		}
	}
	return 0;
}

