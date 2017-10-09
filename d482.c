 /*
  * @file d482.c
  * @author Jason3e7
  * @algorithm DP
  * @date 201710101010
  */

#include <stdio.h>
int main() {
	int n, map[101][101], i, j;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			} 
		}
		for(i = 1; i < n; i++) {
			map[i][0] += map[i - 1][0];
		}
		for(j = 1; j < n; j++) {
			map[0][j] += map[0][j - 1];
		}
		for(i = 1; i < n; i++) {
			for(j = 1; j < n; j++) {
				if(map[i - 1][j] > map[i][j - 1]) {
					map[i][j] += map[i - 1][j];
				} else {
					map[i][j] += map[i][j - 1];
				}
			} 
		}
		printf("%d\n", map[n - 1][n - 1]);
	}
	return 0;
}

