 /*
  * @file b915.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710060939
  */

#include <stdio.h>
int main() {
	int n, point[1001][2], i, j, temp0, temp1;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d %d", &point[i][0], &point[i][1]);
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < (n - 1 - i); j++) {
				if(point[j][0] > point[j + 1][0]) {
					temp0 = point[j][0];
					point[j][0] = point[j + 1][0];
					point[j + 1][0] = temp0;
					temp1 = point[j][1];
					point[j][1] = point[j + 1][1];
					point[j + 1][1] = temp1;
				}
			}
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < (n - 1 - i); j++) {
				if(point[j][0] == point[j + 1][0] && point[j][1] > point[j + 1][1]) {
					temp1 = point[j][1];
					point[j][1] = point[j + 1][1];
					point[j + 1][1] = temp1;
				}
			}
		}
		for(i = 0; i < n; i++) {
			printf("%d %d\n", point[i][0], point[i][1]);
		}
	}
	return 0;
}

