/*
 * @file c129.c
 * @author Jason3e7
 * @algorithm enumeration
 * @date 201512151023
 */


#include <stdio.h>

int m, n, count;
char map[101][101];

void setMap(int x, int y) {
	int i, j;
	if (0 > x || x >= m || 0 > y || y >= n)
		return;
	if (map[x][y] == '@') {
		map[x][y] = '*';
		setMap(x - 1, y - 1);
		setMap(x - 1, y);
		setMap(x - 1, y + 1);
		setMap(x, y - 1);
		setMap(x, y + 1);
		setMap(x + 1, y - 1);
		setMap(x + 1, y);
		setMap(x + 1, y + 1);
	}
	return;
}

int main() {
	int i, j;
	while(scanf("%d %d", &m, &n) != EOF) {	
		if (m == 0 && n == 0)
			break;
		for (i = 0; i < m; i++)
			scanf("%s", map[i]);
		count = 0;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (map[i][j] == '@') {
					count++;
					setMap(i, j);
				}
			}
		}	
		printf("%d\n", count);
	}
	return 0;
}

