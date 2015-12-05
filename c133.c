 /*
  * @file c133.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512051426
  */

#include <stdio.h>
#define chessSize 5

int n, map[chessSize][chessSize], findMax;

void setMap(int x, int y, int flag) {
	map[x][y] += flag;
	int i;
	for (i = x + 1; i < n; i++) {
		if (map[i][y] < 0)
			break;
		map[i][y] += flag;
	}
	for (i = y + 1; i < n; i++) {
		if (map[x][i] < 0)
			break;
		map[x][i] += flag;
	}
	for (i = x - 1; i >= 0; i--) {
		if (map[i][y] < 0)
			break;
		map[i][y] += flag;
	}
	for (i = y - 1; i >= 0; i--) {
		if (map[x][i] < 0)
			break;
		map[x][i] += flag;
	}
	return;
}

void DFS(int beginX, int beginY, int count) {
	int i, j;
	if (count > findMax) {
		findMax = count;
	}
	
	for (i = beginX; i < n; i++) {
		for (j = beginY; j < n; j++) {
			if (map[i][j] == 0) {
				setMap(i, j, 1);
				DFS(beginX, beginY, count + 1);
				setMap(i, j, -1);
			}
		}
	}	
	return;
}

int main() {
	int i, j, sum;
	char temp[chessSize];
	while(scanf("%d", &n) != EOF) {
		if (n == 0)
			break;
		
		for (i = 0; i < n; i++) {
			scanf("%s", &temp);
			for (j = 0; j < n; j++) {
				if (temp[j] == 'X') {
					map[i][j] = -1;
				} else {	
					map[i][j] = 0;
				}
			}
		}
		findMax = 0;
		DFS(0, 0, 0);
		printf("%d\n", findMax);
	}
	return 0;
}
