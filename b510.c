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

void DFSc(int x, int q, int c) {
	int i, j;
	if(q == 0 && c == 0) {
		findSum++;
		return;
	}
	for (i = x; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			if (map[i][j] == 0) {
				setMap(i, j, 1, 'c');
				DFSc(i + 1, q, c - 1);
				setMap(i, j, -1, 'c');
			}
		}
	}		
	return;
}

void DFSq(int x, int q, int c) {
	int i, j;
	if(q == 0) {
		DFSc(1, 0, c);
		return;
	}
	if(q > (size + 1 - x)) {
		return;
	}
	for (i = x; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			if (map[i][j] == 0) {
				setMap(i, j, 1, 'q');
				DFSq(i + 1, q - 1, c);
				setMap(i, j, -1, 'q');
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
		DFSq(1, m, n);
		printf("%d\n", findSum);
	}
	return 0;
}
