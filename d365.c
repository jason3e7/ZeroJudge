/*
 * @file d365.c
 * @author Jason3e7
 * @algorithm enumeration
 * @date 201512161036
 */

#include <stdio.h>

int h, w;
char map[101][101];

void setMap(int x, int y, char target) {
	int i, j;
	if (0 > x || x >= h || 0 > y || y >= w)
		return;
	if (map[x][y] == target) {
		map[x][y] = '*';
		setMap(x - 1, y, target);
		setMap(x, y - 1, target);
		setMap(x, y + 1, target);
		setMap(x + 1, y, target);
	}
	return;
}

int main() {
	int i, j;
	int n, caseNum = 1, ans[26], max;
	scanf("%d", &n);
	while(n--) {	
		scanf("%d %d", &h, &w);
		for (i = 0; i < h; i++)
			scanf("%s", map[i]);
		
		for (i = 0; i < 26; i++)
			ans[i] = 0;
		max = 0;

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (map[i][j] != '*') {
					ans[map[i][j] - 'a']++;
					setMap(i, j, map[i][j]);
				}
			}
		}
		for (i = 0; i < 26; i++)
			if (max < ans[i])
				max = ans[i];

		printf("World #%d\n", caseNum);
		for (i = max; i >= 1; i--)
			for (j = 0; j < 26; j++)
				if (ans[j] == i) 
					printf("%c: %d\n", j + 'a', i);
		caseNum++;
	}
	return 0;
}

