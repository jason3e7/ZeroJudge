 /*
  * @file d263.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512081000
  */

#include <stdio.h>
#define size 9

int n, n2, map[size][size], find;

void debug() {
	int i, j;
	for (i = 0; i < n2; i++) {
		for (j = 0; j < n2; j++) {
			if (j != (n2 - 1))
				printf("%d ", map[i][j]);
			else
				printf("%d\n", map[i][j]);
		}
	}
	printf("\n");
}

int check(int x, int y, int num) {
	int i, j;
	for (i = 0; i < n2; i++) { 
		//printf("x %d %d\n", i ,y);
		if (map[i][y] == num) {
			return 0;
		}
	}
	//printf("x ok\n");
	for (j = 0; j < n2; j++) {
		//printf("y %d %d\n", x ,j);
		if (map[x][j] == num) { 
			return 0;
		}
	}
	//printf("y ok\n");
	int iBegin, iEnd, jBegin, jEnd;
	iBegin = (x / n) * n;
	iEnd = iBegin + n;
	jBegin = (y / n) * n;
	jEnd = jBegin + n;
	for (i = iBegin; i < iEnd; i++) {
		for (j = jBegin; j < jEnd; j++) { 
			if (map[i][j] == num) { 
				return 0;
			}
		}
	}
	return 1;
	
}

void DFS(int x, int y, int count) {
	int i, j, k;
	if (find == 1)
		return;
	if (count == 0) {
		find = 1;
		for (i = 0; i < n2; i++) {
			for (j = 0; j < n2; j++) {
				if (j != (n2 - 1))
					printf("%d ", map[i][j]);
				else
					printf("%d\n", map[i][j]);
			}
		}
		return;
	}
	
	if (y >= n2) {
		y -= n2;
		x++;
	}

	if (map[x][y] != 0) {
		DFS(x, y + 1, count);
	} else {
		//printf("%d %d is Zero\n", x, y);
		for (k = 1; k <= n2; k++) {
			//printf("check %d %d %d\n", x, y, k);
			if (check(x, y, k) == 1) {
				map[x][y] = k;
				//debug();
				DFS(x, y + 1, count - 1);
				map[x][y] = 0;
			}
		}
	}
	return;
}

int main() {
	int i, j, count, flag, temp;
	while(scanf("%d", &n) != EOF) {
		count = 0;
		flag = 0;
		n2 = n * n;
		for (i = 0; i < n2; i++) 
			for (j = 0; j < n2; j++) 
				map[i][j] = 0;
		for (i = 0; i < n2; i++) {
			for (j = 0; j < n2; j++) {
				scanf("%d", &temp);
				if (temp == 0) {
					count++;
				} else { 
					if (check(i, j, temp) == 0)
						flag = 1;	
				}
				map[i][j] = temp;
			}
		}
		find = 0;
		if (flag == 0)
			DFS(0, 0, count);
		if (find == 0)
			printf("NO SOLUTION\n");
	}
	return 0;
}
