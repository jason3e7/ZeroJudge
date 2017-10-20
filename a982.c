 /*
  * @file a982.c
  * @author Jason3e7
  * @algorithm brute force
  * @date 201710201314
  */

#include <stdio.h>
#include <string.h>

char map[101][101];
int n = 0, min = 1000000;
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int walk(int x, int y, int count) {
	if(count > min) {
		return 0;
	}
	if(x == (n - 2) && y == (n - 2)) {
		if(count < min) {
			min = count;
		}
		return 0;
	} 
	int i;
	for(i = 0; i < 4; i++) {
		if(map[x + direction[i][0]][y + direction[i][1]] == '.') {
			map[x][y] = '#';
			walk(x + direction[i][0], y + direction[i][1], count + 1);
			map[x][y] = '.';
		}
	}
	return 0;
}

int main() {
	int i;
	while(scanf("%d", &n) != EOF) {
		min = 1000000;
		for(i = 0; i < n; i++) {
			scanf("%s", map[i]);
		}
		walk(1, 1, 1);
		if(min == 1000000) {
			printf("No solution!\n");
		} else {
			printf("%d\n", min);
		}
	}
	return 0;
}

