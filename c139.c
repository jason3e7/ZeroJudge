 /*
  * @file c139.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511232236
  */

#include <stdio.h>

int map[6][6] = {0}, ans[9];

void DFS(int n, int count) {	
	ans[count] = n;
	int i;
	if (count == 8) {
		for(i = 0; i < 9; i++) 
			printf("%d", ans[i]);
		printf("\n");
		return;
	}
	for (i = 1; i <= 5; i++) {
		if (map[i][n] == 1) {
			map[i][n] = 0;
			map[n][i] = 0;
			DFS(i, count + 1);
			map[i][n] = 1;
			map[n][i] = 1;
		}
	}	
}

int main() {
	map[1][2] = 1;
	map[1][3] = 1;
	map[1][5] = 1;
	map[2][3] = 1;
	map[2][5] = 1;
	map[3][4] = 1;
	map[3][5] = 1;
	map[4][5] = 1;
	map[2][1] = 1;
	map[3][1] = 1;
	map[5][1] = 1;
	map[3][2] = 1;
	map[5][2] = 1;
	map[4][3] = 1;
	map[5][3] = 1;
	map[5][4] = 1;
	DFS(1, 0);
	return 0;
}
