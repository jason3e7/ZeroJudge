 /*
  * @file d412.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511301030
  */

#include <stdio.h>

char operator[100];

int p, num[102], find;

void DFS(int locate, int sum) {
	int i;
	if (find == 1)
		return;
	
	if (locate == p) {
		if (sum == num[p]) {
			find = 1;
			printf("%d", num[0]);
			for(i = 1; i < p; i++) {
				printf("%c%d", operator[i], num[i]);
			}
			printf("=%d\n", num[p]);
		}
		return;
	}

	if (!(32000 >= sum && sum >= -32000)) 
		return;
	
	operator[locate] = '+';
	DFS(locate + 1, sum + num[locate]);	
	operator[locate] = '-';
	DFS(locate + 1, sum - num[locate]);			
	operator[locate] = '*';
	DFS(locate + 1, sum * num[locate]);			
	if (sum % num[locate] == 0) {
		operator[locate] = '/';
		DFS(locate + 1, sum / num[locate]);
	}
}

int main() {
	int i, n;
	scanf("%d", &n);
	while(n--) {
		find = 0;
		scanf("%d", &p);
		for (i = 0; i <= p; i++) 
			scanf("%d", &num[i]);
		DFS(1, num[0]);
		if (find == 0)
			printf("NO EXPRESSION\n");
	}
	return 0;
}
