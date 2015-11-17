/*
 * @file d286.c
 * @author Jason3e7
 * @algorithm backtracking
 * @date 201511092333
 */

#include <stdio.h>

int lines[101][101], points[101];

void setColor() {
	if (allSet()) {
		return blockNum();
	}
	int i;
	for (i = 1; i <= n; i++) {
		if (points[i] == 0) {
			points[i] = 1;
			setColor();
			points[i] = 0;
		}
	}
}



int main() {
	int t, n, k, i, j, pointA, pointB;
	while(scanf("%d", &t) != EOF) 
		while(t--) 
			while(scanf("%d %d", &n, &k) != EOF) {
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
				
					



			}

	return 0;
}


/*
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) 
				printf("%d ", field[i][j]);
			printf("\n");
		}
		
		printf("Count : %d\n", getCount(3, 1));
*/
