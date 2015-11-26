 /*
  * @file d762.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511261000
  */

#include <stdio.h>

int num[5], isUse[5] = {0};
char symbol[5];

int DFS(int count, int sum) {
	int i, j;
	if (count == 6) {
		if (sum == 23) {
			for (i = 1; i <= 5; i++) {
				for (j = 0; j < 5; j++) {
					if (i == isUse[j]) {
						printf("%d", num[j]);
					}
				}
				if (i != 5)
					printf(" %c ", symbol[i + 1]);
			}
			printf("\n");
		}
		return 0;	
	}
	for (i = 0; i < 5; i++) {
		if (isUse[i] == 0) {
			isUse[i] = count;
			symbol[count] = '+';
			DFS(count + 1, sum + num[i]);
			symbol[count] = '-';
			DFS(count + 1, sum - num[i]);
			symbol[count] = '*';
			DFS(count + 1, sum * num[i]);
			symbol[count] = ' ';
			isUse[i] = 0;
		}
	}
	return 1;
}

int main() {
	int i, flag;
	while(scanf("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]) != EOF) {
		flag = 1;
		for (i = 0; i < 5; i++) 
			if (num[i] != 0)
				flag = 0;
		if (flag == 1)
			break;
		
		//flag = 0;
		for (i = 0; i < 5; i++) {
			isUse[i] = 1;
			//flag = DFS(1, num[i]);
			DFS(2, num[i]);
			isUse[i] = 0;
			/*
			if (flag == 1)
				break;
			*/
		}
		/*
		if (DFS() == 1)	
			printf("Possible\n");
		else
			printf("Impossible\n");
		*/
	}
	return 0;
}
