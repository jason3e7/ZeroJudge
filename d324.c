 /*
  * @file d324.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512050924
  */

#include <stdio.h>
#define chessSize 9

int initX, initY, map[chessSize][chessSize], ans[chessSize], find;

void setMap(int x, int y, int flag) {
	if (flag == 1) 
		ans[x] = y;
	else if (flag == -1)
		ans[x] = 0;
	int i, j;
	for (i = 1; i < chessSize; i++)
		map[x][i] += flag;
	for (i = 1; i < chessSize; i++)
		map[i][y] += flag;
	for (i = x, j = y; i >= 1 && j >= 1; i--, j--) 
		map[i][j] += flag;
	for (i = x, j = y; i < chessSize && j < chessSize; i++, j++) 
		map[i][j] += flag;
	for (i = x, j = y; i >= 1 && j < chessSize; i--, j++) 
		map[i][j] += flag;
	for (i = x, j = y; i < chessSize && j >= 1; i++, j--) 
		map[i][j] += flag;
	return;
}

void DFS(int beginX, int count) {
	int i, j;
	if (count == 8) {
		printf("%2d      ", find + 1);
		for (i = 1; i < chessSize; i++) {
			if (i != (chessSize - 1))
				printf("%d ", ans[i]);
			else
				printf("%d\n", ans[i]);
		}
		find++;
		return;
	}
	
	if (beginX == initX) {
		DFS(beginX + 1, count);	
	}

	for (i = 1; i < chessSize; i++) {
		if (map[beginX][i] == 0) {
			setMap(beginX , i, 1);
			DFS(beginX + 1, count + 1);
			setMap(beginX, i, -1);
		}
	}	
	
	return;
}


int main() {
	int i, j, n;
	scanf("%d", &n);
	while (n--) {
		for (i = 1; i < chessSize; i++) {
			for (j = 1; j < chessSize; j++) 
				map[i][j] = 0;
			ans[i] = 0;
		}
		find = 0;
		scanf("%d %d", &initY, &initX);	
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		setMap(initX ,initY, 1);
		DFS(1, 1);
		if (n > 0)
			printf("\n");
	}
	return 0;
}
