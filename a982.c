 /*
  * @file a982.c
  * @author Jason3e7
  * @algorithm BFS
  * @date 201710201314
  */

#include <stdio.h>
#include <string.h>

int map[101][101] = {0}, point[101][2] = {0}, pIndex = 0;
int n = 0, min = 1000000;
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int walk(int count) {
	int i, j, x, y, tPoint[101][2] = {0}, tIndex = 0;
	if(pIndex == 0) {
		return 0;
	}
	for(i = 0; i < pIndex; i++) {
		for(j = 0; j < 4; j++) {
			x = point[i][0] + direction[j][0];
			y = point[i][1] + direction[j][1];
			if(map[x][y] == 0) {
				map[x][y] = count + 1;
				tPoint[tIndex][0] = x;
				tPoint[tIndex][1] = y;
				tIndex++;
			}
			if(x == n - 2 && y == n - 2) {
				return 0;
			}
		}
	}
	for(i = 0; i < tIndex; i++) {
		point[i][0] = tPoint[i][0];
		point[i][1] = tPoint[i][1];
	}
	pIndex = tIndex;
	walk(count + 1);
	return 0;
}

int main() {
	int i, j;
	char input[101][101];
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%s", input[i]);
			for(j = 0; j < n; j++) {
				if(input[i][j] == '#') {
					map[i][j] = -1;
				}
				if(input[i][j] == '.') {
					map[i][j] = 0;
				}
			}
		}
		pIndex = 0;
		if(map[1][1] == 0) {
			map[1][1] = 1;
			point[pIndex][0] = 1;
			point[pIndex][1] = 1;
			pIndex++;
			walk(1);
		}
		if(map[n - 2][n - 2] <= 0) {
			printf("No solution!\n");
		} else {
			printf("%d\n", map[n - 2][n - 2]);
		}
	}
	return 0;
}

