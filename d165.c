/*
 * @file d165.c
 * @author Jason3e7
 * @date 201510011135
 */

#include <stdio.h>

int field[102][102], n, m;

int getCount(int i, int j) {
	
	int sum = field[i][j];
	field[i][j] = 0;
	
	if (field[i - 1][j] != 0) 
		sum += getCount(i - 1, j);
	if (field[i + 1][j] != 0) 
		sum += getCount(i + 1, j);
	if (field[i][j - 1] != 0) 
		sum += getCount(i, j - 1);
	if (field[i][j + 1] != 0) 
		sum += getCount(i, j + 1);
	
	return sum;
}

int main() {
	int i, j, max, count, tempSum;
	while(scanf("%d %d", &n, &m) != EOF) {
		for (i = 0; i < 102; i++) 
			for (j = 0; j < 102; j++) 
				field[i][j] = 0;
		for (i = 1; i <= n; i++) 
			for (j = 1; j <= m; j++) 
				scanf("%d", &field[i][j]);
		
		count = 0;
		max = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (field[i][j] != 0) {
					count++;
					tempSum = getCount(i, j);
					if (tempSum > max) {
						max = tempSum;
					}
				}
			}
		}
		
		printf("%d\n%d\n", count, max);
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
