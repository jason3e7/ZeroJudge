/*
 * @file d286.c
 * @author Jason3e7
 * @algorithm backtracking, DFS
 * @date 201511092333
 */

#include <stdio.h>

int lines[101][101], points[101], n, maxPoint[101], maxCount;

void setColor(int num, int tempCount) {
	int i;
	if (num > n) {
		if (tempCount > maxCount) {
			maxCount = tempCount;
			for (i = 1; i <= n; i++) 
				maxPoint[i] = points[i];
		}
		return;
	}

	if (n - num + 1 + tempCount <= maxCount)
		return;

	if (points[num] != 0)
		setColor(num + 1, tempCount);

	int canSetBlack = 1;
	for (i = 1; i <= n; i++) {
		if (lines[num][i] == 1) { 
			if (points[i] == 1) {
				canSetBlack = 0; 
				break;
			}
		}
	}

	if (canSetBlack == 1) {
		points[num] = 1;
		for (i = 1; i <= n; i++) 
			if (lines[num][i] == 1) 
				points[i] = 2;
		setColor(num + 1, tempCount + 1);
	}

	points[num] = 2;
	setColor(num + 1, tempCount);
	
	points[num] = 0;
}

int main() {
	int t, k, i, j, pointA, pointB, fOut;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &k); 
		for (i = 1; i <= n; i++) {
			points[i] = 0;
			for (j = 1; j <= n; j++)
				lines[i][j] = 0;
		}

		for (i = 0; i < k; i++) {
			scanf("%d %d", &pointA, &pointB);
			lines[pointA][pointB] = 1;
			lines[pointB][pointA] = 1;
		}
		maxCount = 0;
		setColor(1, 0);
		printf("%d\n", maxCount);
		fOut = 1;
		for (i = 1; i <= n; i++) {
			if (maxPoint[i] == 1) {
				if (fOut == 1) {
					printf("%d", i);
					fOut = 0;
				} else { 
					printf(" %d", i);
				}
			}
		}
		printf("\n", i);
	}
	return 0;
}
