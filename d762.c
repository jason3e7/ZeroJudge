 /*
  * @file d762.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511261000
  */

#include <stdio.h>

int num[5], isUse[5] = {0}, find;

void DFS(int count, int sum) {
	int i;
	if (find == 1)
		return;
	if (count == 6) {
		if (sum == 23)
			find = 1;
		return;
	}
	for (i = 0; i < 5; i++) {
		if (isUse[i] == 0) {
			isUse[i] = count;
			DFS(count + 1, sum + num[i]);
			DFS(count + 1, sum - num[i]);
			DFS(count + 1, sum * num[i]);
			isUse[i] = 0;
		}
	}
	return;
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
		
		find = 0;
		for (i = 0; i < 5; i++) {
			isUse[i] = 1;
			DFS(2, num[i]);
			isUse[i] = 0;	
			if (find == 1)
				break;
		}
		if (find == 1)	
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0;
}
