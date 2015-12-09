 /*
  * @file d352.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512091051
  */

#include <stdio.h>
#define size 9
#define length 3

int map[size][size], flag;

int check(int x, int y, int num) {
	int i, j;
	for (i = 0; i < size; i++)  
		if (map[i][y] == num) 
			return 0;
	for (j = 0; j < size; j++) 
		if (map[x][j] == num)  
			return 0;
	int iBegin, iEnd, jBegin, jEnd;
	iBegin = (x / length) * length;
	iEnd = iBegin + length;
	jBegin = (y / length) * length;
	jEnd = jBegin + length;
	for (i = iBegin; i < iEnd; i++) 
		for (j = jBegin; j < jEnd; j++) 
			if (map[i][j] == num) 
				return 0;
	return 1;
	
}

void DFS(int x, int y, int count) {
	int i, j, k;
	if (flag == 2)
		return;
	if (count == 0) {
		flag++;
		return;
	}
	
	if (y >= size) {
		y -= size;
		x++;
	}

	if (map[x][y] != 0) {
		DFS(x, y + 1, count);
	} else {
		for (k = 1; k <= size; k++) {
			if (check(x, y, k) == 1) {
				map[x][y] = k;
				DFS(x, y + 1, count - 1);
				map[x][y] = 0;
			}
		}
	}
	return;
}

int main() {
	int i, j, temp, count, caseNum = 1;;
	while(scanf("%d", &temp) != EOF) {
		flag = 0;
		count = 0;
		for (i = 0; i < size; i++) 
			for (j = 0; j < size; j++) 
				map[i][j] = 0;

		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				if (!(i == 0 && j == 0))
					scanf("%d", &temp);
				if (temp == 0) {
					count++;
				} else { 
					if (check(i, j, temp) == 0)
						flag = -1;	
				}

				map[i][j] = temp;
			}
		}
		if (flag != -1)
			DFS(0, 0, count);

		printf("Case %d: ", caseNum);
		switch (flag) {
			case -1:
				printf("Illegal.\n");
				break;
			case 0:
				printf("Impossible.\n");
				break;
			case 1:
				printf("Unique.\n");
				break;
			case 2:
				printf("Ambiguous.\n");
				break;
		}

		caseNum++;
	}
	return 0;
}
