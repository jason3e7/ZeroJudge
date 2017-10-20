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

int walk(int x, int y, int count) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%s\n", map[i]);
	}
	printf("%d %d %d\n", x, y, count);
	if(x == (n - 2) && y == (n - 2)) {
		if(count < min) {
			min = count;
		}
		return 0;
	} 
	if(map[x + 1][y] == '.') {
		map[x][y] = '#';
		walk(x + 1, y, count + 1);
		map[x][y] = '.';
	}
	if(map[x - 1][y] == '.') {
		map[x][y] = '#';
		walk(x - 1, y, count + 1);
		map[x][y] = '.';
	}
	if(map[x][y + 1] == '.') {
		map[x][y] = '#';
		walk(x, y + 1, count + 1);
		map[x][y] = '.';
	}
	if(map[x][y - 1] == '.') {
		map[x][y] = '#';
		walk(x, y - 1, count + 1);
		map[x][y] = '.';
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
		printf("%d\n", min);
	}
	return 0;
}

