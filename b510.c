 /*
  * @file b510.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201710261001
  */

#include <stdio.h>

int map[10][10], size, findSum = 0;

void setMap(int x, int y, int flag, char c) {
	int i, j;
	for (i = 1; i <= size; i++)
		map[x][i] += flag;
	for (i = 1; i <= size; i++)
		map[i][y] += flag;
	if(c == 'q') {
		for (i = x, j = y; i >= 1 && j >= 1; i--, j--) 
			map[i][j] += flag;
		for (i = x, j = y; i <= size && j <= size; i++, j++) 
			map[i][j] += flag;
		for (i = x, j = y; i >= 1 && j <= size; i--, j++) 
			map[i][j] += flag;
		for (i = x, j = y; i <= size && j >= 1; i++, j--) 
			map[i][j] += flag;
	}
	return;
}

void DFS(int x, int q, int c, char flag) {
	int i, j;
	if(q == 0 && c == 0) {
		findSum++;
		return;
	}
	if(q == 0 && flag == 'q') {
		DFS(1, q, c, 'c');
		return;
	}
	if(q > (size + 1 - x)) {
		return;
	}
	for (i = x; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			if (map[i][j] == 0) {
				setMap(i, j, 1, flag);
				if(flag == 'q') {
					DFS(i + 1, q - 1, c, flag);
				}
				if(flag == 'c') {
					DFS(i + 1, q, c - 1, flag);
				}
				setMap(i, j, -1, flag);
			}
		}
	}		
	return;
}

int main() {
	int i, j, n, m;
	while(scanf("%d %d", &m, &n) != EOF) {
		size = n + m;
		for (i = 1; i <= size; i++) {
			for (j = 1; j < size; j++) {
				map[i][j] = 0;
			}
		}
		findSum = 0;
		DFS(1, m, n, 'q');
		printf("%d\n", findSum);
	}
	return 0;
}
