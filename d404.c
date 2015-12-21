/*
 * @file d404.c
 * @author Jason3e7
 * @algorithm dynamicProgramming
 * @date 201512211014
 */

#include <stdio.h>

int r, c, map[101][101], ans[101][101];

void setEnd() {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (i > 0 && map[i - 1][j] < map[i][j]) 
				continue;
			if (j > 0 && map[i][j - 1] < map[i][j]) 
				continue;
			if ((i + 1) < r && map[i + 1][j] < map[i][j]) 
				continue;
			if ((j + 1) < c && map[i][j + 1] < map[i][j]) 
				continue;
			ans[i][j] = 1;
		}
	}
	return;
}

int DP(int x, int y) {
	if (ans[x][y] != 0)
		return ans[x][y];
	int max = 0;
	if (x > 0 && map[x][y] > map[x - 1][y] && DP(x - 1, y) > max)
		max = DP(x - 1, y);
	if (y > 0 && map[x][y] > map[x][y - 1] && DP(x, y - 1) > max)
		max = DP(x, y - 1);
	if ((x + 1) < r && map[x][y] > map[x + 1][y] && DP(x + 1, y) > max)
		max = DP(x + 1, y);
	if ((y + 1) < c && map[x][y] > map[x][y + 1] && DP(x, y + 1) > max)
		max = DP(x, y + 1);
	max++;
	ans[x][y] = max;
	return max;
}

int main() {
	int n, i, j, maxLength;
	char s[25];
	scanf("%d", &n);
	while(n--) {
		scanf("%s %d %d", &s, &r, &c);
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				scanf("%d", &map[i][j]);
				ans[i][j] = 0;
			}
		}
		setEnd();
		maxLength = 0;
		for (i = 0; i < r; i++) 
			for (j = 0; j < c; j++) 
				if (DP(i, j) > maxLength) 
					maxLength = DP(i, j);
		printf("%s: %d\n", s, maxLength);
	}
	return 0;
}

// Top-down
// Bottom-up level by level !?
